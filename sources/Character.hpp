#include <iostream>
#include <string>

#include "Point.hpp"

using namespace std;


class Character
{
    Point location;
    int hit_points;
    string name;


    public:

    Character(string n, Point l, int hpoint)
    {
        location = l;
        hit_points = hpoint;
        name = n;
    }

    void setLocation(Point p)
    {
        location = p;
    }
    Point getLocation()
    {
        return location;
    }

    string getName()
    {
        return name;
    }

    bool isAlive()
    {
        return hit_points > 0;
    }

    double distance(Character* c)
    {
        Point p1 = c->getLocation();
        
        return location.distance(p1);
    }

    void Hit(int h)
    {
        if(hit_points - h >= 0 )
        {
            hit_points -= h;
        }
        else    
        {
            hit_points=0;
        }
    }

    int getHits(){return hit_points;}

    virtual void shoot(Character* c)=0;

    virtual string print()
    {
        string str="";
        if(hit_points > 0) // if the character is alive
        {
            str=  name + " " + to_string(hit_points) +  location.print();
        
        }
        else
        {
            str=  "(" + name + ")";
        }
        return str;

    }

    virtual ~Character()
    {
        
    }
};

class Cowboy : public Character
{
    char type='C';
    int nBullets;

    public:
    Cowboy(string n, Point l):Character(n, l, 110), nBullets(6){}

    int getNBullets()
    {
        return nBullets;
    }

    void shoot(Character* enemey)
    {
        if(enemey->isAlive() && nBullets > 0)
        {
            enemey->Hit(10);
            nBullets--;
        }

        if(nBullets <=0)
        {
            reload();
        }
    }

    bool hasBullets()
    {
        return nBullets > 0;
    }

    void reload()
    {
        nBullets += 10;
    }

    string print()
    {
        return "C " + Character::print();
    }

};

class ninja: public Character
{
    int speed;

    public:
    ninja(string name, Point loc, int hpoint, int s): Character(name,loc,hpoint)
    {
        speed =s;
    }

    void move(Character* enemy)
    {
        double d_p1_p2 = this->distance(enemy);
        double a = this->getLocation().getX() + (speed / d_p1_p2) * (enemy->getLocation().getX() - this->getLocation().getX());
        double b = this->getLocation().getY() + (speed / d_p1_p2) * (enemy->getLocation().getY() - this->getLocation().getY());
        this->setLocation(Point{a,b});
    }

    void shoot(Character* enemy)
    {
        if(this->isAlive() && this->distance(enemy) < 1)
        {
            enemy->Hit(40);
        }
        else
        {
            this->move(enemy);
        }
    }

    void slash(Character* enemey)
    {
        this->shoot(enemey);
    }

    string print()
    {
        return "N " + Character::print();
    }
};

class YoungNinja: public ninja
{
    public:
    YoungNinja(string n, Point loc, int hits=100, int speed=14):ninja(n,loc,hits,speed){}
};

class TrainedNinja: public ninja
{
    public:
    TrainedNinja(string n, Point loc, int hits=120, int speed=12):ninja(n,loc,hits,speed){}
};

class OldNinja: public ninja
{
    public:
    OldNinja(string n, Point loc, int hits=150, int speed=8):ninja(n,loc,hits,speed){}
};