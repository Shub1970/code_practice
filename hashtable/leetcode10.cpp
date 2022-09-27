// https://leetcode.com/problems/top-k-frequent-elements/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool comp(vector<int> &s1, vector<int> &s2)
{
    return s1[1] > s2[1];
}
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> maap;
        for (auto in : nums)
        {
            maap[in]++;
        }
        vector<vector<int>> temp;
        for (auto x : maap)
        {
            temp.push_back({x.first, x.second});
        }
        sort(temp.begin(), temp.end(), comp);
        vector<int> result;
        for (int i{0}; i < k; i++)
        {
            result.push_back(temp[i][0]);
        }
        return result;
    }
};
// better solution, use heap
int main()
{
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k{2};
    Solution obj;
    vector<int> res = obj.topKFrequent(nums, k);
    for (auto x : res)
    {
        cout << x << " ";
    }
}
