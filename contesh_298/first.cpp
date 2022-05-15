#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &strs)
    {
        vector<string> res;
        map<string, int> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (m.find(s) == m.end())
            {
                m[s] = 1;
                res.push_back(s);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> res = s.removeAnagrams(strs);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}