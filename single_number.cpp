/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
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
};

int main()
{
    Solution s;
    vector<int> nums = {2, 2, 1};
    s.singleNumber(nums);
    return 0;
}