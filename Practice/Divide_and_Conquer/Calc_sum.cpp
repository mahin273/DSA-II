#include <vector>
#include<iostream>

int calc_sum(const std::vector<int>& arr, int start, int end) {
    // Base case: if the array has one element, return it
    if (start == end) {
        return arr[start];
    }

    // Recursive case: split the array into two halves and calculate the sum of each half
    int mid = start + (end - start) / 2;
    return calc_sum(arr, start, mid) + calc_sum(arr, mid + 1, end);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = calc_sum(arr, 0, arr.size() - 1);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}