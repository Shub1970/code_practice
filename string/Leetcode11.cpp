#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int length = words.size();
        vector<int> time(length, 0);
        for (string st : words)
        {
            for (char ch : st)
            {
                time[ch - 'a']++;
            }
        }
        int common_time = time[0];
        bool ans = true;
        for (int T : time)
        {
            if (T != common_time)
                ans = false;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"abc", "aabc", "bc"};
    cout << s.makeEqual(words);
    return 0;
}