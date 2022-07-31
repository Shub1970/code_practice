#include <iostream>
#include <vector>
using namespace std;
// better way of binary search
int celing(vector<int> &nums, int value)
{
    int left{0}, right(nums.size());
    if (value > nums[nums.size() - 1])
        return -1;
    while (left < right)
    {
        int mid{left + right >> 1};
        if (value > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}

int main()
{
    vector<int> nums{1, 5, 9, 14, 15, 17, 18, 20, 24, 28, 29, 30};
    cout << celing(nums, 31);
}