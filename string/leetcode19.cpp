#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> index(26, 0);
        for (auto ch : s)
        {
            index[ch - 'a']++;
        }
        for (auto ch : t)
        {
            if (index[ch - 'a'] > 0)
                index[ch - 'a']--;
        }

        return accumulate(index.begin(), index.end(), 0);
    }
};

int main()
{
    string s{"leetcode"}, t{"practice"};
    Solution obj;
    cout << obj.minSteps(s, t);
}