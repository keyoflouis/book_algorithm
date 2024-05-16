#include"header.h"



bool compareX(const Point& a,const Point& b) {
	return a.x < b.x;
}
bool compareY(const Point& a, const Point& b) {
	return a.y < b.y;
}

double dist(const Point& p1,const Point& p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(vector<Point>& points,int left,int right) {

	double mindistance = DBL_MAX;

	for (int i = left; i <= right;++i) {
		for (int j = i + 1; j < right; ++j) {
			mindistance = min(mindistance, dist(points[i],points[j]));
		}
	}
	return mindistance;
}

double stripNearest(vector<Point>& strip,double L) {

	sort(strip.begin(),strip.end(),compareY);

	for (int i = 0; i < strip.size();i++) {
		for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < L; j++) {
			L = min(L, dist(strip[i], strip[j]));
		}
	}

	return L;
}

double nearestUtil(vector<Point>& points,int left,int right) {

	if (right - left <= 3) {
		return bruteForce(points,left,right);
	}

	int mid = (left + right) / 2;
	Point midPoint = points[mid];

	double dl = nearestUtil(points, left, mid);
	double dr = nearestUtil(points, mid + 1, right);

	double L = min(dl, dr);

	vector<Point> strip;

	for (int i = left; i <= right; i++) {
		if ((points[i].x - points[mid].x) < L) {
			strip.push_back(points[i]);
		}
	}

	return min(L, stripNearest(strip,L));

}

double nearest(vector<Point>& points) {

	sort(points.begin(), points.end(), compareX);
	return nearestUtil(points, 0, points.size() - 1);

}