#include <string>
#include <iostream>
#include "turtle.h"
#include "svgdrawer.h"
#include "menu.h"
#include "menuoption.h"
#include "menuaction.h"
#include "command.h"
#include "InputHandling.h"
#include "menulogo.h"

using namespace std;

int main(){ // a lot of testing, the main is only there to create and execute Menu
    /**** INFO: TEST SCRIPT
    InputHandling test1 = InputHandling("fd 10 turn 20 ");
    InputHandling test2 = InputHandling("fd 10 repeat 2 [turn 10] clear"); // fd 10 turn 10 turn 10 clear
    InputHandling test3 = InputHandling("fd 10 repeat 2 [turn 10 repeat 2 [fd -5] turn -5] clear");
    test1.deloop();
    test2.deloop();
    test3.deloop();
    std::cout << test1.delooped() << endl;
    std::cout << test2.delooped() << endl;
    std::cout << test3.delooped() << endl;
    test1.vectorize();
    test2.vectorize();
    test3.vectorize();
    cout << endl;
    int i = 0;
    for(string it : test1.vectorized()){
        cout << i << ": " << it << ' ';
        i++;
    }
    i = 0;
    cout << endl;
    for(string it : test2.vectorized()){
        cout << i << ": " << it << ' ';
        i++;
    }
    i = 0;
    cout << endl;
    for(string it : test3.vectorized()){
        cout << i << ": "<< it << ' ';
        i++;
    }
    cout << endl;

    test1.parse();

    cout << endl;
    i = 0;
    for(const auto& it : test1.result()){
        cout << i << ": ";
        it->display();
        cout << ' ';
        i++;
    }
    
    */
    MenuLogo menu;
    menu.execute();
    return 0;
}
