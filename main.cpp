#include "turtle.h"
#include "svgdrawer.h"
#include "menu.h"
#include "menuoption.h"
#include "menuaction.h"
#include "utils.h"
#include <string>
#include <iostream>

int main(){
    std::string test1 = "fd 10 turn 20 ";
    std::string test2 = "fd 10 repeat 2 [turn 10] clear"; // fd 10 turn 10 turn 10 clear
    std::string test3 = "fd 10 repeat 2 [turn 10 repeat 2 [fd -5] turn -5] clear";
    // fd 10 (turn 10 fd -5 fd -5 turn -5) turn 10 fd -5 fd -5 turn -5 clear
    std::cout << deloop(test1) << endl;
    std::cout << deloop(test2) << endl;
    std::cout << deloop(test3) << endl;
    vector<string> test1vec = vectorize(deloop(test1));
    vector<string> test2vec = vectorize(deloop(test2));
    vector<string> test3vec = vectorize(deloop(test3));
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