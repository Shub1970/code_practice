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

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        stack<int, vector<int>> stac(nums);
        unordered_map<int, int> mp;
        int index = 0;
        while (!stac.empty())
        {
            if (!stac.top())
            {
                while (!stac.top() && !stac.empty())
                {
                    mp[index]++;
                    stac.pop();
                }
                index++;
            }
            else
                stac.pop();
        }
        long long ans{0};
        for (auto x : mp)
        {
            ans += x.second * (x.second + 1) / 2;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{0, 0, 0, 2, 0, 0};
    Solution obj;
    cout << obj.zeroFilledSubarray(nums);
}
