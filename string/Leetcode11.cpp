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
        vector<int> time(26, 0);
        for (string st : words)
        {
            for (char ch : st)
            {
                time[ch - 'a']++;
            }
        }
        int common_time = length;
        bool ans = true;
        for (int T : time)
        {
            if (T != 0)
            {
                if (T != common_time)
                    ans = false;
            }
        }
        for (auto st : time)
        {
            cout << st << " ";
        }
        cout << endl;
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