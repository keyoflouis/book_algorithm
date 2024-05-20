#include"header.h"

int partition(int arr[],int l,int r) {
	int j = l ;
	int v = arr[l];
	for (int i = l+1; i <= r;i++) {
		if (arr[i]<v) {
			swap(arr[++j], arr[i]);
		}
	}
	swap(arr[j], arr[l]);
	return j;
}

void __quickSort(int arr[],int l,int r) {

	if (l >= r) {
		return;
	}

	int p = partition(arr,l,r);


	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);

	return;
}	

void quickSort(int arr[],int n) {
	
	__quickSort(arr, 0, n - 1);

}