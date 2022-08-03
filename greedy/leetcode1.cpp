#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.com/problems/array-partition/
// better way to solve is to greedy about groping two max value to get bet min value out of two
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum{0};
        for (int i{0}; i < nums.size() - 1; i++)
        {
            sum += min(nums[i], nums[i + 1]);
        }
        return sum;
    }
};