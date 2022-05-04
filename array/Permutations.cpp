/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>
using namespace std;
// write a fuction for generating permutations

class Solution
{
public:
    void solve(vector<int> &nums, int start, vector<vector<int>> &result)
    {
        if (start == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            solve(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        solve(nums, 0, result);
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> result = s.permute(nums);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}