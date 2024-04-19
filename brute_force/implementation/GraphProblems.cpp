// convex hull
#include"header.h"

vector<covexHull_point> convexHull(vector<covexHull_point> n){
    set<covexHull_point> set_hull;
     
    for (int i = 0; i < n.size();i++)
    {
        for (int j = i+1; j < n.size();j++)
        {
            covexHull_point A = n[i];
            covexHull_point B = n[j];

            int a = B.y - A.y;
            int b = A.x - B.x;
            int c = A.x * B.y - B.x * A.y;

            int flag1 = 0;
            int flag2 = 0;

            for(auto p:n){
                float result = a * p.x + b * p.y - c;
                if(result>=0){
                    flag1++;
                }else if(result <=0){
                    flag2++;
                }
            }

            if(flag1 == n.size()|| flag2 ==n.size()){
                set_hull.insert(A);
                set_hull.insert(B);
            }
        }
    }

    vector<covexHull_point> hull(set_hull.begin(),set_hull.end());

    return hull;
}