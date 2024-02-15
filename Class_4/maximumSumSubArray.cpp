#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSumOfFourElements(vector<int> &nums)
{
    if (nums.size() < 4)
    {
        return 0; 
    }

    sort(nums.begin(), nums.end(),greater<int>());

    return nums[0] + nums[1] + nums[2] + nums[3];
}

int main()
{
    vector<int> nums = {-50, 20, 13, 5, 6, -10, 2, 1};
    int max_sum = maxSumOfFourElements(nums);
    cout << "maximum sum : " << max_sum << std::endl;

    return 0;
}