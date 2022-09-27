// https://leetcode.com/problems/top-k-frequent-elements/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<string> copy_string(strs);
        for (auto &sub_string : copy_string)
        {
            sort(sub_string.begin(), sub_string.end());
        }
        unordered_map<string, vector<string>> maap;
        for (int i{0}; i < strs.size(); i++)
        {
            maap[copy_string[i]].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto mp : maap)
        {
            result.push_back(mp.second);
        }
        return result;
    }
};
int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution obj;
    vector<vector<string>> res = obj.groupAnagrams(strs);
    for (auto r : res)
    {
        for (auto x : r)
        {
            cout << x << " ";
        }
    }
}