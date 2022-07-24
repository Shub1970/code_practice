#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        vector<vector<int>> index(24);
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i] - 'a'].push_back(i);
        }
        for (auto x : index)
        {
            if (x.size() < 1)
                x.push_back(INT32_MAX);
        }
        char max;
        int min_value = INT32_MAX;
        int ind = 0;
        for (auto P : index)
        {
            if (P[1] < min_value)
            {
                min_value = P[1];
                max = 'a' + ind;
                ind++;
            }
        }
        return max;
    }
};