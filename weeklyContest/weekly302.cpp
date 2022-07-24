#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// maximum Number of pairs in array
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto x : nums)
        {
            mp[x]++;
        }
        int ans = 0;
        for (auto m : mp)
        {
            if (m.second & 1)
                ans += (m.second - 1) / 2;
            else
                ans += m.second / 2;
        }
        int second = nums.size() - ans * 2;
        return {ans, second};
    }
};

int main()
{
    vector<int> nums{1, 1};
    Solution obj;
    vector<int> ans = obj.numberOfPairs(nums);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}