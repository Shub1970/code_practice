#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
bool comp(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &strs)
    {
        int len = strs.size();
        int i = 1;
        while (i < len)
        {
            if (comp(strs[i - 1], strs[i]))
            {
                strs.erase(strs.begin() + i);
                len--;
            }
            else
                i++;
        }
        return strs;
    }
};
int main()
{
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> res = s.removeAnagrams(strs);
    for (auto i : res)
    {
        cout << i << endl;
    }
}