#include"header.h"


void __merge(int arr[],int l,int mid, int r) {
	int* aux = (int*)malloc(sizeof(int)*(r - l + 1));

	for (int i = l; i <= r;i++) {
		aux[i - l ] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if(j > r ){
			arr[k] = aux[i - l];
			i++;
		}
		else if(aux[i-l] >= aux[j-l])
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i++;
		}
	}

	free(aux);
}

void merge(int arr[],int l,int r) {

	if (l>=r) {
		return;
	}

	int mid = (l + r) / 2;
	merge(arr, l, mid);
	merge(arr, mid + 1, r);

	__merge(arr,l,mid,r);
}


void mergeSort(int arr[],int n) {
	merge(arr, 0, n - 1);
}