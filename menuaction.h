#ifndef MENUACTION_H
#define MENUACTION_H

#include <string>
#include "menuoption.h"


template <class T> class MenuAction : public MenuOption
{
  typedef bool (T::*ActionPtr)(int);
  ActionPtr actionFct_;
public:
  MenuAction(std::string text="", ActionPtr actionFct=nullptr);
  bool isValid() const {return actionFct_!=nullptr;}
  bool execute(Menu *menu, int menuId);
};

template <class T> MenuAction<T>::MenuAction(std::string text, ActionPtr actionFct) : MenuOption(text)
{
  actionFct_=actionFct;
}


template <class T> bool MenuAction<T>::execute(Menu *menu, int menuId)
{
  bool quit=false;
  T* menuT = dynamic_cast<T*>(menu);            // it must be a T*
  if (actionFct_!=nullptr && menuT!=nullptr) {
      quit=(menuT->*actionFct_)(menuId);
    }
  return quit;
}




#endif // MENUACTION_H
