#include<vector>
#include<iostream>
#include<set>
using namespace std;

class covexHull_point{
    public:
        int x, y;
    covexHull_point(int x,int y){
        this->x = x;
        this->y = y;
    }

    bool operator < (const covexHull_point& p )const{
        return x < p.x || (x == p.x && y < p.y);
    }
};
vector<covexHull_point> convexHull(vector<covexHull_point> n);