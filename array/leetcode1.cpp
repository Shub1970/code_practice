#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        map<string, int> mp;
        mp["type"] = 0;
        mp["color"] = 1;
        mp["name"] = 2;
        int count{0};
        for (auto item : items)
        {
            if (item[mp[ruleKey]] == ruleValue)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution obj;
    obj.countMatches();
}