// https://leetcode.com/problems/find-and-replace-pattern/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
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
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        map<char, int> mp;
        for (auto p : pattern)
            mp[p]++;
        vector<int> patt;
        for (auto x : mp)
        {
            patt.push_back(x.second);
        }
        cout << "pattern";
        for (auto x : patt)
            cout << x << "-";
        vector<string> result;
        for (auto word : words)
        {
            vector<int> temp_patt;
            map<char, int> mp;
            for (auto w : word)
                mp[w]++;
            for (auto x : mp)
            {
                temp_patt.push_back(x.second);
            }
            cout << "\n";
            for (auto x : temp_patt)
                cout << x << "-";
            if (comp(patt, temp_patt))
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
    // for (auto st : res)
    // {
    //     cout << st << "\n";
    // }
}
