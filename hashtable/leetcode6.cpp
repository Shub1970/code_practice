#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        int index{0};
        for (int i{0}; i < pattern.size(); i++)
        {
            string temp;
            for (index; index < s.size(); index++)
            {
                if (s[index] != ' ')
                    temp.push_back(s[index]);
                else
                {
                    ++index;
                    break;
                }
            }
            if (mp.find(pattern[i]) != mp.end())
            {
                if (mp[pattern[i]] != temp)
                    return false;
            }
            else
            {
                mp[pattern[i]] = temp;
            }
        }
        return true;
    }
};