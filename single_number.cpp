/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/* class Solution
{
public:
    void singleNumber(vector<int> &nums)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                m[nums[i]] = 1;
            }
            else
            {
                m[nums[i]]++;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second == 1)
            {
                cout << it->first << endl;
            }
        }
    }
}; */

// this solition is not good, because it use extra space
// the reason is that we need to store the number in the map, but the map is not a good choice, because it will use extra space
// the map is a good choice when the number is not too large, but the number is too large, the map will use too much space
// Time complexity: O(n)
// Space complexity: O(n)

//--------------let use sort method to solve this problem------------
/* class Solution
{
public:
    void singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (nums[i] != nums[i + 1])
                {
                    cout << nums[i] << endl;
                    return;
                }
            }
        }
    }
}; */
// Time complexity: O(nlogn)
// Space complexity: O(1)
// sort method is a good choice, but the time complexity is not good, and not linear

//--------------let use bit manipulation to solve this problem------------
class Solution
{
public:
    void singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        cout << res << endl;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)
// bit manipulation is a good choice
int main()
{
    Solution s;
    vector<int> nums = {2, 2, 1};
    s.singleNumber(nums);
    return 0;
}
