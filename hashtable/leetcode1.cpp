// hashtable
// no of good pair
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > 1)
            {
                ans += (it->second * (it->second - 1)) / 2;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << s.numIdenticalPairs(nums);
    return 0;
}