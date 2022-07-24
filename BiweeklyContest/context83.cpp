#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// best poker hand

// class Solution
// {
// public:
//     string bestHand(vector<int> &ranks, vector<char> &suits)
//     {
//         unordered_map<char,vector<int>>mp;
//         for(int i{0};i<suits.size();i++){
//             mp[suits[i]].push_back(ranks[i]);
//         }
//         for(auto m:mp){
//             if(mp.size()==1)return "Flush";
//             else if ()
//             {
//             }

//         }
//     }
// };

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
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        vector<int> zeroSize;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = 0;
            if (!nums[i])
            {
                while (!nums[i] && i < nums.size())
                {
                    temp++;
                    i++;
                }
                zeroSize.push_back(temp);
            }
        }
        long long ans{0};
        for (auto x : zeroSize)
        {
            ans += x * (x + 1) / 2;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{1, 3, 0, 0, 2, 0, 0, 4};
    Solution obj;
    cout << obj.zeroFilledSubarray(nums);
}
