#include"./implementation/header.h"

int main() {
	std::vector<covexHull_point> n = { {1,2}, {2,3}, {6,3}, {2,2},{1,3}, {2,4} };
	std::vector<covexHull_point> convex_hull = convexHull(n);


	for (auto& p : convex_hull) {
		std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
	}

	return 0;
}
