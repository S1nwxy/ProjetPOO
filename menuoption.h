#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <string>
#include <list>

class Menu;


class MenuOption
{
  std::string text_;
public:
  MenuOption(std::string text="");
  virtual ~MenuOption();
  std::string text() const {return text_;}
  virtual bool isValid() const {return false;}
  virtual bool isMenu() const {return false;}
  virtual bool execute(Menu *menu, int menuId)=0;
};



#endif // MENUOPTION_H
