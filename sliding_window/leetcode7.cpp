#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool map_value_check(unordered_map<int, int> &nums)
    {
        for (auto mp : nums)
        {
            if (mp.second > 1)
                return true;
        }
        return false;
    }
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        int temp_max = 0;
        int first = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[i]++;
            max_sum = max(max_sum, temp_max);
            bool test = map_value_check(mp);
            while (test)
            { // start shrinking
                temp_max -= nums[first];
                mp[nums[first]]--;
                first++;
            }
            temp_max += nums[i];
        }
        return max(temp_max, max_sum);
    }
};

int main()
{
    vector<int> nums{4, 2, 4, 5, 6};
    Solution obj;
    cout << obj.maximumUniqueSubarray(nums);
}