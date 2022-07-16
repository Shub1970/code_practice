#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:

    int maximumUniqueSubarray(vector<int> &nums)
    {
        int max_sum = 0;
        int temp_max = 0;
        int first = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[i]++;
            max_sum = max(max_sum, temp_max);
            bool test = [&mp]()->bool{for(auto m:mp){if(m.second>1)return true;}return false;}();
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