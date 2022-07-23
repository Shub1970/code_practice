#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int ans = 0;
        priority_queue<pair<int, int>> pq;
        priority_queue<pair<int, int>> qp;
        for (int i = 1; i <= nums.size(); i++)
        {
            pq.push({nums[i - 1], -i});
        }
        vector<int> ret;
        int K = k;
        while (K--)
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            qp.push({temp.second, temp.first});
        }
        while (k--)
        {
            ret.push_back(qp.top().second);
            qp.pop();
        }
        return ret;
    }
};

int main()
{
    vector<int> nums{-1, -2, 3, 4};
    Solution obj;
    vector<int> ans = obj.maxSubsequence(nums, 3);
    for (auto x : ans)
        cout << x << " ";
}