#include"header.h"

int interpolationSearch(int arr[],int n,int x){

    int low = 0;
    int high = n - 1;

    while (low <= high &&arr[low] <= x && arr[high] >= x)
    {
        int pos = low + (high - low) / (arr[high] - arr[low]) * (x - arr[low]);
        if(x == arr[pos]){
            return pos;
        }

        if(x <arr[pos] ){

            high = pos - 1;
        }

        if(x > arr[pos]){
            low = pos + 1;
        }

    }
    return -1;
}