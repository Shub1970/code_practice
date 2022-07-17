#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int nice_subarray = 0;
        for (int i = 0, start = 0, count_odd = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2)
                count_odd++;
            if (count_odd == k)
                nice_subarray++;
            while (count_odd == k)
            {
                int k = 0;
                if (nums[i] % 2)
                    count_odd--;
                start++;
            }
        }
        return nice_subarray;
    }
};

int main()
{
    vector<int> nums{1, 1, 2, 1, 1};
    int k = 3;
    Solution obj;
    cout << obj.numberOfSubarrays(nums, k) << endl;
}