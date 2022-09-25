// https://leetcode.com/problems/find-and-replace-pattern/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
using namespace std;
class Solution
{

public:
    bool comp(vector<int> &a, vector<int> &b)
    {
        bool res{true};
        for (int i{0}; i < a.size() && a.size() == b.size(); i++)
        {
            if (a[i] != b[i])
                res = false;
        }
        return res;
    }
    vector<int> pattern_creater(string pattern)
    {
        vector<int> patt;
        char initial_stage{pattern[0]};
        int val{0};
        for (auto x : pattern)
        {
            if (initial_stage == x)
                val++;
            else
            {
                patt.push_back(val);
                initial_stage = x;
                val = 1;
            }
        }
        patt.push_back(val);
        return patt;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<int> patt = pattern_creater(pattern);
        vector<string> result;
        for (auto word : words)
        {
            vector<int> tem_patt = pattern_creater(word);
            if (comp(patt, tem_patt))
                result.push_back(word);
        }
        return result;
    }
};
int main()
{
    vector<string> words = {"a", "b", "c"};
    string pattern = "a";
    Solution obj;
    vector<string> res = obj.findAndReplacePattern(words, pattern);
    for (auto st : res)
    {
        cout << st << "\n";
    }
}
