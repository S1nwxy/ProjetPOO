#include <iostream>
#include <limits>
#include <cstdlib>
#include "menu.h"
#include "menuoption.h"

using namespace std;

#ifdef _WIN32
void clearConsole() {
  system("cls");
}
#else
void clearConsole() {
  system("clear");
}
#endif

void pauseConsole(string text) {
  cout<<text;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  string s;
  getline(cin,s,'\n');
}


Menu::Menu(string title, string prompt, string errorMessage) : MenuOption(title)
{
  prompt_=prompt;
  errorMessage_=errorMessage;
}

Menu::~Menu()
{
  for (MenuOption *op : options_)
    delete op;
}

void Menu::print() const
{
  cout<<text()<<endl<<endl;
  int i=1;
  for(const MenuOption * opt : options_) {
      cout<<"- "<<i<<": "<<opt->text()<<endl;
      i++;
    }
}


MenuOption *Menu::findOption(int choice) const
{
  int i=1;
  auto it=options_.begin();
  while (it!=options_.end() && i!=choice) {
    it++;
    i++;
    }
  if (it==options_.end())
    return nullptr;
  else
    return *it;
}

MenuOption *Menu::promptUser(int &menuId) const
{
  MenuOption *option=nullptr;
  menuId=0;

  clearConsole();
  print();
  cout<<endl;
  cout<<prompt_<<": ";

  int choice;
  cin>>choice;
  if (!cin.fail()) {
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      option=findOption(choice);
      menuId=choice;
    }
  else {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  cout<<endl;
  if (option==nullptr || !option->isValid()) {
      cout<<errorMessage_<<endl;
      pauseConsole();
    }

  return option;
}


bool Menu::execute(Menu *menu, int)
{
  bool quit=false;
  if (menu==nullptr)
    menu=this;
  while(!quit) {
      MenuOption *option;
      int menuId;
      option=promptUser(menuId);

      if (option!=nullptr) {
          quit=option->execute(menu,menuId);
          if (!quit && !option->isMenu() && option->isValid())
            pauseConsole();
        }
    }
  return 0;
}
