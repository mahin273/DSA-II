#include <iostream>
#include <vector>

int mergeAndCount(std::vector<int>& arr, int start, int mid, int end) {
    int i, j, k;
    int inv_count = 0;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inv_count += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inv_count;
}

int count_inversion(std::vector<int>& arr, int start, int end) {
    int inv_count = 0;
    if (start < end) {
        int mid = start + (end - start) / 2;
        inv_count += count_inversion(arr, start, mid);
        inv_count += count_inversion(arr, mid + 1, end);
        inv_count += mergeAndCount(arr, start, mid, end);
    }
    return inv_count;
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

    int inversions = count_inversion(A, 0, N - 1);

    std::cout << "Number of inversions: " << inversions << std::endl;

    return 0;
}