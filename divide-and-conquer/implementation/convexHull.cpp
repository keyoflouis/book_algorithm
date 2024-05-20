#include"header.h"



bool CompareVertex(const Vertex& a, const Vertex& b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    else {
        return a.x < b.x;
    }
}

Points FindHull(const Points& originSet, const Vertex& p1, const Vertex& p2, bool findUpper) {
    Points upperSet;

    Vertex p_max;
    double maxDistance = -1.0;
    for (auto iter = originSet.begin(); iter != originSet.end(); iter++) {
        double distance = p1.x * p2.y + (iter->x) * p1.y + p2.x * (iter->y) - (iter->x) * p2.y - p2.x * p1.y - p1.x * (iter->y);
        if ((findUpper && distance > 0.0) || (!findUpper && distance < 0.0)) {
            upperSet.push_back(*iter);
            distance = std::abs(distance);
            if (distance > maxDistance) {
                p_max = (*iter);
                maxDistance = distance;
            }
        }
    }

    if (maxDistance > 0.0) {
        Points SubHull1 = FindHull(upperSet, p1, p_max, findUpper);
        Points SubHull2 = FindHull(upperSet, p_max, p2, findUpper);
        SubHull1.insert(SubHull1.begin(), SubHull2.begin(), SubHull2.end());
        SubHull1.push_back(p_max);
        return SubHull1;
    }
    else {
        return Points(); // empty
    }
}

Points QuickHull(const Points& originSet) {
    Points sortedSet = originSet;
    std::sort(sortedSet.begin(), sortedSet.end(), CompareVertex);

    Points upperHull = FindHull(sortedSet, sortedSet.front(), sortedSet.back(), true);
    Points lowerHull = FindHull(sortedSet, sortedSet.front(), sortedSet.back(), false);

    upperHull.insert(upperHull.begin(), lowerHull.begin(), lowerHull.end());
    upperHull.push_back(sortedSet.front());
    upperHull.push_back(sortedSet.back());

    return upperHull;
}

void PrintPoints(const Points& points) {
    for (const auto& vertex : points) {
        std::cout << vertex.x << ' ' << vertex.y << std::endl;
    }
}


/* // some logical mistake check it later

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


struct convexHull_point {
	int x;
	int y;
	//convexHull_point() {
	//	x = 0;
	//	y = 0;
	//}
	//convexHull_point(int x,int y):x(x),y(y) {

	//}
};

bool comparX(const convexHull_point& A,const convexHull_point& B) {

	return A.x < B.x || (A.x == B.x && A.y < B.y);
}

// true left ,false right
bool leftOrRight(const convexHull_point& A,const  convexHull_point& B,const convexHull_point& C) {
	return (A.x * B.y + C.x * A.y + B.x * C.y - C.x * B.y - B.x * A.y - A.x * C.y) > 0 ? true : false;
}

vector<convexHull_point>  convertToS1(const vector<convexHull_point>& points, convexHull_point first, convexHull_point last) {
	vector<convexHull_point> S1; //left										  

	for (auto point : points) {
		if (leftOrRight(first, last, point) && !(point.x == first.x && point.y == first.y) && !(point.x == last.x && point.y == last.y)) {
			S1.push_back(point);
		}
	}

	return S1;
}

vector<convexHull_point>  convertToS2(const vector<convexHull_point>& points, convexHull_point first, convexHull_point last) {
	vector<convexHull_point> S2; //right

	for (auto point : points) {
		if (!leftOrRight(first, last, point) && !(point.x == first.x && point.y == first.y) && !(point.x == last.x && point.y == last.y)) {
			S2.push_back(point);
		}
	}

	return S2;
}

// the distance to vector AB 
double distance(convexHull_point A, convexHull_point B, convexHull_point C) {
	double numerator = abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
	double denominator = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
	return numerator / denominator;
}

convexHull_point find_pmax(vector<convexHull_point> points, convexHull_point A, convexHull_point B) {

	convexHull_point tempMax;
	double max_distance = 0;
	for (auto point : points) {
		double dist = distance(A, B, point);
		if (max_distance < dist) {
			max_distance = dist;
			tempMax = point;
		}
	}

	return tempMax;
}

vector<convexHull_point>
ridPointInTheVectorCircle(vector<convexHull_point> points,
	convexHull_point first, 
	convexHull_point last, 
	convexHull_point upPmax) 
{
	for (vector<convexHull_point>::iterator i = points.begin(); i != points.end(); ) {
		if (leftOrRight(first, last, *i) == leftOrRight(last, upPmax, *i) == leftOrRight(upPmax, first, *i)) {
			i = points.erase(i);
		}
		else {
			++i;
		}
	}
	return points;
}

vector<convexHull_point> convexHullUtil(vector<convexHull_point>& points, convexHull_point first, convexHull_point last) {
	if (points.size() <= 2) {
		return points;
	}

	vector<convexHull_point> S1 = convertToS1(points,first,last);

	convexHull_point upPmax = find_pmax(S1, first, last);
	S1 = ridPointInTheVectorCircle(S1,first,last,upPmax);

	vector<convexHull_point> S2 = convertToS2(points, first, last);
	convexHull_point belowPmax = find_pmax(S2, first, last);
	S2 = ridPointInTheVectorCircle(S2, first, last, belowPmax);

	vector<convexHull_point> result;
	vector<convexHull_point> temp = convexHullUtil(S1, first, upPmax);
	result.insert(result.end(), temp.begin(), temp.end());

	vector<convexHull_point> temp1 = convexHullUtil(S1, upPmax, last);
	result.insert(result.end(), temp1.begin(),temp1.end());

	vector<convexHull_point> temp2 = convexHullUtil(S2, first, belowPmax);
	result.insert(result.end(),temp2.begin(), temp2.end());

	vector<convexHull_point> temp3 = convexHullUtil(S2, belowPmax, last);
	result.insert(result.end(), temp3.begin(), temp3.end());

	return result;

}

vector<convexHull_point> convexHull(vector<convexHull_point> points) {

	sort(points.begin(), points.end(), comparX);
	convexHull_point first = points.front();
	convexHull_point last = points.back();

	return convexHullUtil(points, first, last);
}



int main() {
	vector<convexHull_point> points = { {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3} };
	vector<convexHull_point> result = convexHull(points);

	for (auto& point : result) {
		cout << "(" << point.x << ", " << point.y << ")" << endl;
	}

	return 0;
}


*/



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stack>

// // ai graham scan
// using namespace std;


// struct Point {
//     int x, y;
// };
// Point next_to_top(stack<Point>& S);

// // A utility function to find the bottom-most or left-most point
// bool compare(Point p1, Point p2) {
//     return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
// }

// // A utility function to return the square of distance
// // between p1 and p2
// int distSq(Point p1, Point p2) {
//     return (p1.x - p2.x) * (p1.x - p2.x) +
//         (p1.y - p2.y) * (p1.y - p2.y);
// }

// // To find orientation of ordered triplet (p, q, r).
// // 0 -> p, q and r are collinear
// // 1 -> Clockwise
// // 2 -> Counterclockwise
// int orientation(Point p, Point q, Point r) {
//     int val = (q.y - p.y) * (r.x - q.x) -
//         (q.x - p.x) * (r.y - q.y);

//     if (val == 0) return 0;
//     return (val > 0) ? 1 : 2;
// }

// // A function used by std::sort() to sort an array of
// // points with respect to the first point
// bool comparePolar(Point p0, Point p1, Point p2) {
//     // Find orientation
//     int o = orientation(p0, p1, p2);
//     if (o == 0)
//         return distSq(p0, p2) >= distSq(p0, p1);
//     return (o == 2);
// }

// void convexHull(vector<Point> points) {
//     int n = points.size();
//     if (n < 3) return;

//     // Find the bottom-most point
//     int ymin = points[0].y, min = 0;
//     for (int i = 1; i < n; i++) {
//         int y = points[i].y;
//         if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
//             ymin = points[i].y, min = i;
//     }

//     // Place the bottom-most point at first position
//     swap(points[0], points[min]);

//     // Sort the points based on the polar angle made with the bottom-most point
//     sort(points.begin() + 1, points.end(), [&](Point p1, Point p2) {
//         return comparePolar(points[0], p1, p2);
//         });

//     // If two or more points make the same angle with p0,
//     // remove all but the one that is farthest
//     int m = 1; // Initialize size of modified array
//     for (int i = 1; i < n; i++) {
//         // Keep removing i while angle of i and i+1 is same with respect to p0
//         while (i < n - 1 && orientation(points[0], points[i], points[i + 1]) == 0)
//             i++;

//         points[m] = points[i];
//         m++;  // Update size of modified array
//     }

//     if (m < 3) return;

//     // Create an empty stack and push first three points
//     stack<Point> S;
//     S.push(points[0]);
//     S.push(points[1]);
//     S.push(points[2]);

//     // Process remaining n-3 points
//     for (int i = 3; i < m; i++) {
//         // Keep removing top while the angle formed by points next-to-top,
//         // top, and points[i] makes a non-left turn
//         while (S.size() > 1 && orientation(next_to_top(S), S.top(), points[i]) != 2)
//             S.pop();
//         S.push(points[i]);
//     }

//     // Now stack has the output points, print contents of stack
//     while (!S.empty()) {
//         Point p = S.top();
//         cout << "(" << p.x << ", " << p.y << ")" << endl;
//         S.pop();
//     }
// }

// // Utility function to return next to top in a stack
// Point next_to_top(stack<Point>& S) {
//     Point p = S.top();
//     S.pop();
//     Point res = S.top();
//     S.push(p);
//     return res;
// }

// int main() {
//     vector<Point> points = { {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3} };
//     convexHull(points);

//     return 0;
// }