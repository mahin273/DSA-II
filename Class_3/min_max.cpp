#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> findMinMax(int arr[], int low, int high)
{
    if (low == high)
    {
        return make_pair(arr[low], arr[high]);
    }

   
    int mid = low + (high - low) / 2;
    pair<int, int> leftPair = findMinMax(arr, low, mid);
    pair<int, int> rightPair = findMinMax(arr, mid + 1, high);

    return make_pair(max(leftPair.first, rightPair.first), min(leftPair.second, rightPair.second));
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> result = findMinMax(arr, 0, n - 1);
    cout << "Max element: " << result.first << ", Min element: " << result.second << endl;
    return 0;
}