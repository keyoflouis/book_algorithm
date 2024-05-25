#include"header.h"

int main(){
    std::vector<int> A = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    std::cout << "Original array: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    ComparisonCountingSort(A);

    std::cout << "Sorted array: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}