#include <iostream>
#include <vector>
#include <climits>

struct Subarray {
    int start, end, sum;
};

Subarray crossSubarray(const std::vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = mid;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    return {maxLeft, maxRight, leftSum + rightSum};
}

Subarray find_max_sum_subarray(std::vector<int>& arr, int low, int high) {
    if (high == low) {
        return {low, high, arr[low]};
    } else {
        int mid = (low + high) / 2;
        Subarray leftSubarray = find_max_sum_subarray(arr, low, mid);
        Subarray rightSubarray = find_max_sum_subarray(arr, mid + 1, high);
        Subarray crossSub = crossSubarray(arr, low, mid, high);

        if (leftSubarray.sum >= rightSubarray.sum && leftSubarray.sum >= crossSub.sum) {
            return leftSubarray;
        } else if (rightSubarray.sum >= leftSubarray.sum && rightSubarray.sum >= crossSub.sum) {
            return rightSubarray;
        } else {
            return crossSub;
        }
    }
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

    Subarray result = find_max_sum_subarray(A, 0, N - 1);

    std::cout << "Maximum sum subarray: ";
    for (int i = result.start; i <= result.end; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\nSum: " << result.sum << std::endl;

    return 0;
}