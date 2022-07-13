#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double total = 0;
        double max_avg = -10000;
        if (nums.size() == k)
            return accumulate(nums.begin(), nums.end(), 0.0) / k;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            if (i < k - 1)
                continue; // making size of window=k
            double temp_avg = total / k;
            if (max_avg < temp_avg)
                max_avg = temp_avg;
            total -= nums[i - k + 1];
        }
        return max_avg;
    }
};

// can we refactor this, better solution
double findMaxAverage(vector<int> &nums, int k)
{
    double sum = 0, res = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < k)
            sum += nums[i];
        else
        {
            res = max(sum, res);
            sum += nums[i] - nums[i - k];
        }
    }
    res = max(res, sum);
    return res / k;
}

int main()
{
    vector<int> nums{-1};
    int k = 1;
    Solution obj;
    cout << setprecision(5) << obj.findMaxAverage(nums, k);
    return 0;
}