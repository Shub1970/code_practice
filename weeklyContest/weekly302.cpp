#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <functional>
#include <queue>
using namespace std;
// maximum Number of pairs in array
// class Solution
// {
// public:
//     vector<int> numberOfPairs(vector<int> &nums)
//     {
//         unordered_map<int, int> mp;
//         for (auto x : nums)
//         {
//             mp[x]++;
//         }
//         int ans = 0;
//         for (auto m : mp)
//         {
//             if (m.second & 1)
//                 ans += (m.second - 1) / 2;
//             else
//                 ans += m.second / 2;
//         }
//         int second = nums.size() - ans * 2;
//         return {ans, second};
//     }
// };

// int main()
// {
//     vector<int> nums{1, 1};
//     Solution obj;
//     vector<int> ans = obj.numberOfPairs(nums);
//     for (auto x : ans)
//     {
//         cout << x << " ";
//     }
// }

// max sum of a pair with Equal sum of digits

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, priority_queue<int>> mp;
        for (auto x : nums)
        {
            string temp = to_string(x);
            int tem = 0;
            for (auto ch : temp)
                tem += (ch - '0');
            mp[tem].push(x);
        }
        int max = -1;
        for (auto m : mp)
        {
            if (m.second.size() > 1)
            {
                int first{m.second.top()};
                m.second.pop();
                int second{m.second.top()};
                if (max < first + second)
                    max = first + second;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> nums{18, 43, 36, 13, 7};
    Solution obj;
    cout << obj.maximumSum(nums);
}