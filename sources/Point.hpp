#include <iostream>
#include <math.h>

using namespace std;

class Point
{
    double x,y;

    public:
    Point(){x=0;y=0;}
    Point(double a, double b): x(a), y(b){}

    double getX(){return x;}
    double getY(){return y;}

    double distance(Point p)
    {
        double a = x - p.getX(); 
        double b = y - p.getY();
        double dist;
        dist = pow(a, 2) + pow(b, 2);       //calculating Euclidean distance
        dist = sqrt(dist);                  

        return dist;
    }

    string print()
    {
        return "[" + to_string(x) + ", " + to_string( y) + "]";
    }

    Point moveTowards(Point s, Point d, double dist)
    {
        double dist_to_source = d.distance(s);
        double dist_to_this = this->distance(d);

        Point p;
        if(dist_to_source > dist_to_this)
        {
            p = *this;
        }
        else
        {
            p = s;
        }
        return p;
    }


};