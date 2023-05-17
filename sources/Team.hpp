#include <iostream>
#include "Character.hpp"

using namespace std;

class Team
{
    Character* fighters[10];
    Character* leader;
    int nFighters;

    
    void chooseLeader()
    {
        if(nFighters==0) // if no character then return none
        {
            return;
        }

        Character* nLeader = nullptr;
        double distance = 9999999;
        
        int count=0;
        for(Character* c: fighters)
        {
            if(count++ >= nFighters){break;}

            if(c != leader && c->isAlive() && c->distance(leader) < distance)
            {
                nLeader = c;
                distance= c->distance(leader);
            }
        }

        leader = nLeader;
    }

    public:
    Team(Character* l)
    {
        leader=l;
        fighters[0] = leader;
        nFighters=1;
    }

    void add(Character* f)
    {
        if(nFighters < 10)
        {
            fighters[nFighters]= f;
            nFighters++;
        }
    }



    void attack(Team* enemyTeam)
    {
        if(!leader->isAlive())
        {
            chooseLeader();
            if(leader == nullptr) // if no leader choosen (i.e. no alive fighter remaining)
                {return;}
        }

        Character* closestEnemy = enemyTeam->getClosest(leader);
        if(closestEnemy == nullptr) // there is no closest alive enemy
        {return;}

        // for (int i = 0; i < nFighters; i++)
        int count=0;
        for (Character* c: fighters)
        {
            if(count++ >= nFighters){break;}
            if (c->isAlive())
            {
                c->shoot(closestEnemy);
                if(!closestEnemy->isAlive())
                {
                    closestEnemy = enemyTeam->getClosest(leader);
                    if(closestEnemy == nullptr) // if there is no closest alive enemy the attack will end
                        {return;}
                }
            }
        }
        
    }

    int stillAlive()
    {
        int count=0;
        // for (int i = 0; i < nFighters; i++)
        int counter=0;
        for (Character* c: fighters)
        {
            if(counter++ >= nFighters){break;}
            if (c->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void print()
    {
        cout << endl;
        // for (int i = 0; i < nFighters; i++)
        int count=0;
        for (Character* c: fighters)
        {
            if(count++ >= nFighters){break;}
            cout << c->print();
            if(c == leader)
                {cout << "\t Leader";}
            cout << endl;
        }
        cout << endl;
        
    }

    Character* getClosest(Character *c)
    {
        if(nFighters==0) // if no character then return none
        {return nullptr;}

        Character* f = nullptr;
        double distance = 0,d;
        // for (int i = 0; i < nFighters; i++)
        int count=0;
        for(Character* fighter: fighters)
        {
            if(count++ >= nFighters){break;}
            if(f == nullptr && fighter->isAlive())
            {
                distance= c->distance(fighter);
                f = fighter;
            }
            else if(fighter->isAlive() && fighter->distance(c) < distance)
            {
                f = fighter;
                distance= fighter->distance(c);
            }
        }
        
        return f;
    }

    ~Team()
    {
        // for (int i = 0; i < nFighters; i++)
        int count=0;
        for(Character* c: fighters)
        {
            if(count++ >= nFighters){break;}
            delete c;
        }
    }

};