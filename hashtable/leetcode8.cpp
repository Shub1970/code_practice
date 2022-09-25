// https://leetcode.com/problems/find-and-replace-pattern/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
using namespace std;
bool comp(vector<int> a, vector<int> b)
{
    bool res{true};
    for (int i{0}; i < a.size(); i++)
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
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<int> patt = pattern_creater(pattern);
        vector<string> result;
        for (auto word : words)
        {
            vector<int> tem_patt = pattern_creater(word);
            bool com_equal{true};
            for (int i{0}; i < patt.size(); i++)
            {
                if (patt[i] != tem_patt[i])
                    com_equal = false;
            }
            if (com_equal)
                result.push_back(word);
        }
        return result;
    }
};
int main()
{
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    Solution obj;
    vector<string> res = obj.findAndReplacePattern(words, pattern);
    for (auto st : res)
    {
        cout << st << "\n";
    }
}
