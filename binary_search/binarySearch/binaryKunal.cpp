#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
    int binary_search(vector<int> &nums, int target, string position)
    {
        if (nums.size() == 0)
            return -1;
        int left{0};
        int right = nums.size();
        int ans{-1};
        while (left <= right)
        {
            int mid{left + right >> 1};
            if (target > nums[mid])
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
            else
            {
                ans = mid;
                if (position == "start")
                    right = mid - 1;
                else if (position == "end")
                    left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans{-1, -1};
        ans[0] = binary_search(nums, target, "start");
        if (ans[0] != -1)
            ans[1] = binary_search(nums, target, "end");
        return ans;
    }
};
int main()
{
    vector<int> nums{1};
    int target{1};
    Solution obj;
    vector<int> ans = obj.searchRange(nums, target);
    for (auto x : ans)
        cout << x << " ";
}