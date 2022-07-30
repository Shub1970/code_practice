#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{

public:
    vector<int> ans{0};
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, pair<int, int>> mp;
        for (int i{0}; i < s.size(); i++)
        {
            if (mp.count(s[i]))
            {
                mp[s[i]].second = i;
            }
            else
            {
                mp[s[i]] = {i, i};
            }
        }
        int x{0};
        pair<int, int> range{0, 0};
        while (x < s.size())
        {
            range = mp[s[x]];
            if (mp[s[x]].second - mp[s[x]].first > 0)
            {
                for (x; x <= range.second; x++)
                {
                    if (range.second < mp[s[x]].second)
                        range.second = mp[s[x]].second;
                }
            }
            else
            {
                x++;
            }
            ans.push_back(x);
        }
        vector<int> rest;
        for (int i{1}; i < ans.size(); i++)
        {
            if (ans[i] - ans[i - 1] > 0)
                rest.push_back(ans[i] - ans[i - 1]);
            else
                rest.push_back(1);
        }
        return rest;
    }
};

int main()
{
    Solution obj;
    string s = "zxxxxababcbacadefegdehijhklij";
    vector<int> ans = obj.partitionLabels(s);
    for (auto y : obj.ans)
        cout << y << " ";
    cout << endl;
    for (auto x : ans)
        cout << x << " ";
}