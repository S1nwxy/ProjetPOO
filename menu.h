#ifndef MENU_H
#define MENU_H

#include <list>
#include <string>
#include "menuoption.h"

void clearConsole();
void pauseConsole(std::string text="Press <Enter> to continue...");

class Menu : public MenuOption
{
  std::string prompt_;
  std::string errorMessage_;
  std::list<MenuOption *> options_;
public:
  Menu(std::string title,
       std::string prompt="Votre choix ",
       std::string errorMessage="Option invalide");
  ~Menu();
  bool isValid() const {return true;}
  bool isMenu() const {return true;}
  void addOption(MenuOption *option)
    {options_.push_back(option);}
  virtual void print() const;
  MenuOption *findOption(int choice) const;
  MenuOption *promptUser(int &menuId) const;
  bool execute(Menu *menu=nullptr,int menuId=0);
  bool exitMenu(int) {return true;}
};

#endif // MENU_H
