#include <iostream>
#include <vector>

void print_odd(const std::vector<int>& arr, int start, int end) {
    // Base case: if the array is empty, return
    if (start > end) {
        return;
    }

    // Base case: if the array has one element and it's odd, print it
    if (start == end) {
        if (arr[start] % 2 != 0) {
            std::cout << arr[start] << std::endl;
        }
        return;
    }

    // Recursive case: split the array into two halves and process each half
    int mid = start + (end - start) / 2;
    print_odd(arr, start, mid);
    print_odd(arr, mid + 1, end);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_odd(arr, 0, arr.size() - 1);
    return 0;
}