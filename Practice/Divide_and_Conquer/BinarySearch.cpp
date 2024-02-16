#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binary_search(const std::vector<int>& arr, int start, int end, int X) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == X)
            return mid;

        if (arr[mid] > X)
            return binary_search(arr, start, mid - 1, X);

        return binary_search(arr, mid + 1, end, X);
    }

    return -1;
}

int main() {
    int N, X;
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    std::vector<int> A(N);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << "Enter the element to search: ";
    std::cin >> X;

    quickSort(A, 0, N - 1);

    int index = binary_search(A, 0, N - 1, X);
    if (index != -1)
        std::cout << "Element found at index: " << index << std::endl;
    else
        std::cout << "Element not found in the array" << std::endl;

    return 0;
}