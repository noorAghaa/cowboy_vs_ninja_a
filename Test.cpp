#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include <iostream>
#include <algorithm> // For __gcd; taken from the internet
#include <typeinfo> // For typeid(...)
#include <sstream>
//using namespace ariel;
using namespace std;

TEST_CASE("Point object initialization & Getters return expected values") {
    Point a(32.3,44),b(1.3,3.5);

    // Check that the type of coordinates are int
    CHECK(typeid(a.getX()).name() == typeid(double).name());
    CHECK(typeid(a.getY()).name() == typeid(double).name());

    // Check that the int constractor's fields are like expected. Also checks the getters
    CHECK(((a.getX() == 32.3) && (a.getY() == 44)));

    // Check that the float constractor's fields are like expected
    CHECK(((b.getX() == 1.3) && (b.getY() == 3.5)));

    CHECK(a.distance(b) == b.distance(a));

    CHECK(a.print() == "[32.300000, 44.000000]");
    CHECK(b.print() == "[1.300000, 3.500000]");

    Point c;
    CHECK(c.print() =="[0.000000, 0.000000]");
}

TEST_CASE("Character and Team testing") {
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);

    CHECK(tom->print() == "C Tom 110[32.300000, 44.000000]");
    CHECK(sushi->print() == "N sushi 150[1.300000, 3.500000]");

    tom->shoot(sushi);

    CHECK(tom->print() == "C Tom 110[32.300000, 44.000000]");
    CHECK(sushi->print() == "N sushi 140[1.300000, 3.500000]");

    sushi->move(tom);

    CHECK(tom->print() == "C Tom 110[32.300000, 44.000000]");
    CHECK(sushi->print() == "N sushi 140[6.162511, 9.852636]");

    sushi->slash(tom);

    CHECK(tom->print() == "C Tom 110[32.300000, 44.000000]");
    CHECK(sushi->print() == "N sushi 140[11.025023, 16.205272]");

    CHECK_FALSE(!tom->isAlive());
    CHECK_FALSE(!sushi->isAlive());

    CHECK_FALSE(!tom->isAlive());
    CHECK_FALSE(!sushi->isAlive());

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12,81)));

}
