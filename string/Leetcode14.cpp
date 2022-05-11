#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        int triple = 0;
        int no_delete_char = 0;
        int char_count[26] = {0};
        vector<int> char_index;
        for (int i = 0; i < s.size(); i++)
        {
            for (auto j : char_count)
            {
                cout << j << " ";
            }
            cout << endl;
            char_count[s[i] - 'a']++;
            if (char_count[s[i] - 'a'] == 3)
            {
                triple++;
                char_index.push_back(i);
            }
            if (i < 2)
                continue;
            char_count[s[i - 2] - 'a']--;

            if (char_count[s[i - 1] - 'a'] == 2)
            {
                triple--;
            }
            cout << triple << endl;
        }
        cout << "char_indes"
             << " :";
        for (auto i : char_index)
        {
            s[i] = '*';

            cout << i << " ";
        }
        string ans;
        for (auto c : s)
        {
            if (c == '*')
            {
                continue;
            }
            ans.push_back(c);
        }

        return ans;
    }
};

// normal solution
class Solution
{
public:
    string makeFancyString(string s)
    {
        int cnt = 1;
        string ans = "";
        ans.push_back(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            if (cnt <= 3)
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1 = "aaabaaaa";
    cout << s.makeFancyString(s1) << endl;
    return 0;
}