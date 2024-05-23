#include"header.h"
//
//class MaxHeap {
//
//	double* data;
//	int count;
//	int capacity;
//
//
//	void shiftup(int k) {
//		while (k > 1 && data[k / 2] < data[k]) {
//			swap(data[k / 2], data[k]);
//			k /= 2;
//		}
//	}
//
//	void shiftdown(int k) {
//
//		while (k * 2 <= count)
//		{
//			int j = k * 2;
//			if (j + 1 <= count && data[j + 1] >= data[j]) {
//				j += 1;
//			}
//
//			if (data[k] >= data[j]) {
//				break;
//			}
//
//			swap(data[k], data[j]);
//			k = j;
//		}
//	}
//
//
//public:
//	MaxHeap(int capacity) {
//		data = new double[capacity + 1];
//		count = 0;
//		this->capacity = capacity;
//	}
//
//	~MaxHeap()
//	{
//		delete[]data;
//	}
//
//	int size() {
//		return count;
//	}
//
//	bool isempty() {
//		return count == 0;
//	}
//
//	void insert(double item) {
//		if (count + 1 <= capacity) {
//			data[count + 1] = item;
//			count++;
//			shiftup(count);
//		}
//		else {
//			cout << "capacity is not enough" << endl;
//		}
//
//	}
//
//	double pop() {
//		if (count <= 0) {
//			return -1;
//		}
//		else
//		{
//			int temp = data[1];
//			swap(data[1], data[count]);
//			count--;
//			shiftdown(1);
//			return temp;
//		}
//	}
//};
//
//int main() {
//	MaxHeap maxheap = MaxHeap(100);
//	srand(time(NULL));
//
//	for (int i = 0; i < 50; i++) {
//		maxheap.insert(rand() % 100);
//	}
//	while (!maxheap.isempty())
//	{
//		cout << maxheap.pop() << " ";
//	}
//
//	return 0;
//}