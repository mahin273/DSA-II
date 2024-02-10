#include <iostream>
using namespace std;

int calc_sum(int arr[], int s, int e)
{
    
    if (s == e)
    {
        return arr[s] % 2 == 0 ? arr[s] : 0;
    }

    int mid = s + (e - s) / 2;
    return calc_sum(arr, s, mid) + calc_sum(arr, mid + 1, e);
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
    int sumOfEven = calc_sum(arr, 0, n - 1);
    cout << "Sum of even numbers in the array is: " << sumOfEven << endl;
    return 0;
}