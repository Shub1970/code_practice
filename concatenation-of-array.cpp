/*Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.



Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getConatenation(vector<int> &nums)
    {
        const int siz = nums.size();
        vector<int> ans(2 * siz);
        vector<int>::iterator p;
        int i = 0;
        for (p = nums.begin(); p != nums.end(); p++)
        {
            ans[i] = ans[siz + i] = *p;
            ++i;
        }
        return ans;
    }
};

int main()
{
    vector<int> num{1, 2, 1};
    Solution s;
    vector<int> ans = s.getConatenation(num);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}