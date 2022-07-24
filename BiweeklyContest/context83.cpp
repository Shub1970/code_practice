#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;

// best poker hand

//--------------------------------------------------------------------------------------------------------------------------------------
// class Solution
// {
// public:
//     long long zeroFilledSubarray(vector<int> &nums)
//     {
//         stack<int, vector<int>> stac(nums);
//         unordered_map<int, int> mp;
//         int index = 0;
//         while (!stac.empty())
//         {
//             if (!stac.top())
//             {
//                 while (!stac.top() && !stac.empty())
//                 {
//                     mp[index]++;
//                     stac.pop();
//                 }
//                 index++;
//             }
//             else
//                 stac.pop();
//         }
//         long long ans{0};
//         for (auto x : mp)
//         {
//             ans += x.second * (x.second + 1) / 2;
//         }
//         return ans;
//     }
// };
// problem is if stack size is very big

// better solution
// class Solution
// {
// public:
//     long long zeroFilledSubarray(vector<int> &nums)
//     {
//         vector<int> zeroSize;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             long long temp = 0;
//             if (!nums[i])
//             {
//                 while (!nums[i] && i < nums.size())
//                 {
//                     temp++;
//                     i++;
//                 }
//                 zeroSize.push_back(temp);
//             }
//         }
//         long long ans{0};
//         for (auto x : zeroSize)
//         {
//             ans += x * (x + 1) / 2;
//         }
//         return ans;
//     }
// };

// int main()
// {
//     vector<int> nums{0, 1, 0, 0, 1, 0, 0, 0};
//     Solution obj;
//     cout << obj.zeroFilledSubarray(nums);
// }

//-----------------------------------------------------------------------------------------------------------------------------
// Design a Number container system

class NumberContainers
{
    unordered_map<int, int> mp;

public:
    NumberContainers()
    {
    }
    void change(int index, int number)
    {
        mp[index] = number;
    }
    int find(int number)
    {
        for (auto x : mp)
        {
            if (x.second == number)
                return x.first;
        }
        return -1;
    }
};