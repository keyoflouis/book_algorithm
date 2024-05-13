#include"header.h"

void josephus(list<int>& people, int g) {
	auto i = people.begin();

	while (people.size()!=1)
	{
		for (int j = 0; j < g; j++) {
			if (i!=people.end()) {
				i++;
			}else if(i == people.end()){
				i = people.begin();
			}
		}

		i = people.erase(i);
		if (i == people.end()) {
			i = people.begin();
		}

	}
}
// 
//int josephus(int n, int k) {
//	if (n == 1)
//		return 0;
//	else
//		return (josephus(n - 1, k) + k) % n;
//}