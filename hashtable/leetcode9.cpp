// https://leetcode.com/problems/top-k-frequent-elements/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<string> copy_string(strs);
        for (int i{0}; i < strs.size(); i++)
        {
            strs[i] = sort(strs[i].begin(), strs[i].end());
        }
        map<string, vector<int>> mp;
        for (int i{0}; i < strs.size(); i++)
        {
            mp[copy_string[i]].push_back(i);
        }
        vector<vector<string>> result;
        for (auto m : mp)
        {
            vector<int> temp;
            for (auto x : m.second)
                temp.push_back(strs[i]);
            result.push_back(temp);
        }
        return result;
    }
};