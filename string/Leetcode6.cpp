#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* class Solution
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
}; */
//----------------------------------------------------------------------
// better solution
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int count = 0;
        int dup = 0;
        if (s.size() < 3)
        {
            return 0;
        }
        int mp[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                cout << mp[j] << " ";
            }
            cout << endl;
            cout << "i:" << s[i] << " count:" << count << " dup:" << dup << endl;
            mp[s[i] - 'a']++;
            if (mp[s[i] - 'a'] == 2)
            {
                dup++;
            }
            if (i < 2)
            {
                continue;
            }
            if (dup == 0)
            {
                count++;
            }
            mp[s[i - 2] - 'a']--;
            if (mp[s[i - 2] - 'a'] == 1)
            {
                dup--;
            }
        }
        return count;
    }
};

int main()
{
    cout << "shubham kumar %d" << 32 << endl;
    Solution s;
    string s1 = "aabcddeefghi";
    cout << s.countGoodSubstrings(s1);
    return 0;
}
