#include <iostream>
#include <vector>
#include <array>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> map(26, 0);
        for (auto ch : s)
        {
            map[ch - 'a']++;
        }
        for (int i{0}; i < s.size(); i++)
        {
            if (map[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution obj;
    string st{"loveleetcode"};
    cout << obj.firstUniqChar(st);
}