// https://leetcode.com/problems/sort-characters-by-frequency/
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool comp(string s1, string s2)
{
    return s1.size() > s2.size();
}
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, string> mp;
        for (char x : s)
        {
            mp[x] += x;
        }
        vector<string> st;
        for (auto x : mp)
        {
            st.push_back(x.second);
        }
        sort(st.begin(), st.end(), comp);
        string ret;
        for (auto s : st)
        {
            ret += s;
        }
        return ret;
    }
};

int main()
{
    string s{"cccaaaafdfdsfsdfsdfdsewerrwerwer"};
    Solution obj;
    cout << obj.frequencySort(s);
}