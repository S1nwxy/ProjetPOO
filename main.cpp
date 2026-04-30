#include <string>
#include <iostream>
#include "turtle.h"
#include "svgdrawer.h"
#include "menu.h"
#include "menuoption.h"
#include "menuaction.h"
#include "InputHandling.h"

using namespace std;

int main(){
    Input test1 = Input("fd 10 turn 20 ");
    Input test2 = Input("fd 10 repeat 2 [turn 10] clear"); // fd 10 turn 10 turn 10 clear
    Input test3 = Input("fd 10 repeat 2 [turn 10 repeat 2 [fd -5] turn -5] clear");
    // fd 10 (turn 10 fd -5 fd -5 turn -5) turn 10 fd -5 fd -5 turn -5 clear
    std::cout << test1.deloop() << endl;
    std::cout << test2.deloop() << endl;
    std::cout << test3.deloop() << endl;
    vector<string> test1vec = test1.vectorize(test1.deloop());
    vector<string> test2vec = test2.vectorize(test2.deloop());
    vector<string> test3vec = test3.vectorize(test3.deloop());
    cout << endl;
    for(string it:test1vec){
        cout << it << ' ';
    }
    cout << endl;
    for(string it:test2vec){
        cout << it << ' ';
    }
    cout << endl;
    for(string it:test3vec){
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}