#include"header.h"

void ComparisonCountingSort(std::vector<int>& A) {
    int n = A.size();

    std::vector<int> Count(n, 0);
    std::vector<int> S(n);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] < A[j]) {
                Count[j]++;
            }
            else {
                Count[i]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        S[Count[i]] = A[i];
    }

    for (int i = 0; i < n; ++i) {
        A[i] = S[i];
    }
}

// int main() {
//     std::vector<int> A = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

//     std::cout << "Original array: ";
//     for (int num : A) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     ComparisonCountingSort(A);

//     std::cout << "Sorted array: ";
//     for (int num : A) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
