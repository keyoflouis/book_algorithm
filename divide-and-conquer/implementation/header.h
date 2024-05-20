#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void mergeSort(int arr[], int n);
void quickSort(int arr[], int n);

struct Point
{
	int x;
	int y;
};
double nearest(vector<Point>& points);

struct Vertex {
    double x;
    double y;
};


using Points = std::vector<Vertex>;

Points QuickHull(const Points &originSet);

void PrintPoints(const Points& points);