
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int first = 0;
        int max_size = INT_MIN;
        int count_zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count_zero++;
            while (count_zero > 1)
            {
                if (nums[first] == 0)
                    count_zero--;
                first++;
            }
            max_size = max(max_size, i - first + 1);
        }
        return --max_size;
    }
};
int main()
{
    vector<int> nums{0, 1, 1, 1, 0, 1, 1, 0, 1};
    Solution obj;
    cout << obj.longestSubarray(nums);
}