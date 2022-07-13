// I have to increase my sliding window
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int zero_count = 0;
        int max_size = INT_MIN;
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 0)
                zero_count++;
            while (zero_count > k)
            {
                if (nums[i] == 0)
                {
                    zero_count--;
                }
                i++;
            }
            max_size = max(max_size, j - i + 1);
        }
        return max_size;
    }
};
int main()
{
    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    Solution obj;
    cout << obj.longestOnes(nums, k);
}