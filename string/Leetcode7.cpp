#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        map<char, int> mp;
        for (auto c : chars)
        {
            mp[c]++;
        }
        int ans = 0;
        for (string s : words)
        {
            int times = 0;
            for (auto c : s)
            {
                if (mp[c] > 0)
                {
                    ++times;
                    mp[c]--;
                }
                else
                {
                    break;
                }
            }
            mp.clear();
            for (auto c : chars)
            {
                mp[c]++;
            }
            if (times == s.size())
            {
                ans += s.size();
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    Solution s;
    cout << s.countCharacters(words, chars) << endl;
    return 0;
}