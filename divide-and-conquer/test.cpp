#include"header.h"


int main() {
//     int arr[] = { 1, 2, 3, 5, 67, 87, 86, 5, 56, 7, 89, 0 };
//     int n = sizeof(arr) / sizeof(arr[0]);

//  //   mergeSort(arr, n);
//     quickSort(arr, n);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;

    //vector<Point> points = { {2,6},{3,4},{8,10},{23,3},{10,3} };
    //cout << "the smallest distance is: " << nearest(points) << endl;
    //return 0;

std::vector<Vertex> originSet = { {1.0, 1.0}, {2.0, 2.0}, {3.0, 1.0}, {3.0, 3.0}, {1.0, 3.0} };
std::vector<Vertex> convexHull = QuickHull(originSet);

PrintPoints(convexHull);

return 0;


}