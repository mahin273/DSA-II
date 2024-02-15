#include <iostream>
using namespace std;

int findEven(int arr[], int s, int e)
{

    if (s == e)
    {
        return arr[s] % 2 == 0 ? 1 : 0;
    }

    int mid = s + (e - s) / 2;
    return findEven(arr, s, mid) + findEven(arr, mid + 1, e);
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
    int numberOfEven = findEven(arr, 0, n - 1);
    cout << "Number of even numbers in the array is: " << numberOfEven << endl;
    return 0;
}