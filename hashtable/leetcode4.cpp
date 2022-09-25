#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int current_max_value{0};
        int result{0};
        for (int i(s.size() - 1); i >= 0; i--)
        {
            if (map[s[i]] < current_max_value)
            {
                result -= map[s[i]]
            }
            else
            {
                current_max_value = map[s[i]];
                result += map[s[i]];
            }
        }
        return result;
    }
};
