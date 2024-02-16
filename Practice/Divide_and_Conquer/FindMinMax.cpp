#include <iostream>
#include <vector>
#include <climits>

void findMaxMin(const std::vector<int>& arr, int start, int end, int& min, int& max) {
    // Base case: if the array has one element, return it as both max and min
    if (start == end) {
        min = max = arr[start];
        return;
    }

    // Recursive case: split the array into two halves and find the max and min of each half
    int mid = start + (end - start) / 2;
    int min1 = INT_MAX, max1 = INT_MIN, min2 = INT_MAX, max2 = INT_MIN;
    findMaxMin(arr, start, mid, min1, max1);
    findMaxMin(arr, mid + 1, end, min2, max2);

    // Combine the results: the max is the max of the two maxes, and the min is the min of the two mins
    min = std::min(min1, min2);
    max = std::max(max1, max2);
}

int main() {
    int N;
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    std::vector<int> A(N);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int min = INT_MAX, max = INT_MIN;
    findMaxMin(A, 0, A.size() - 1, min, max);
    std::cout << "Max: " << max << ", Min: " << min << std::endl;

    return 0;
}