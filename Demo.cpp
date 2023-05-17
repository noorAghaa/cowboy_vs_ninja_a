/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

// #include "sources/Character.hpp"
#include "sources/Team.hpp" //no need for other includes

// using namespace ariel;


int main() 
{
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Point c;
    cout << a.print() << " " << b.print() <<" " << c.print() << endl;
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    cout << "Before: \n" << tom->print() << " \n" << sushi->print() << endl;
    tom->shoot(sushi);
    cout << "After Shoot: \n" <<tom->print() <<endl;
    cout << sushi->print() << endl;

    sushi->move(tom);
    cout << "After sushi move towards tom: \n";
    cout << sushi->print() << endl;


    sushi->slash(tom);

    cout << "After sushi slashes top: \n" <<tom->print() <<endl;
    cout << sushi->print() << endl;


    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));

    cout << "TEams" << endl;
    team_A.print();
    team_B.print();

    int count=0;
   return 0;
     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        cout <<"Teams: ";
        team_A.print();
        team_B.print();
        if(count ++ > 300)
         break;
     }

      cout <<"After loop" << endl;
     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
