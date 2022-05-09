#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        if (s.size() < 3)
        {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < s.size() - 2; i++)
        {
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
            {
                ++count;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    string s1 = "A";
    cout << s.countGoodSubstrings(s1);
    return 0;
}