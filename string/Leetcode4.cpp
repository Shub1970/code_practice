#include <iostream>
using namespace std;
/* class Solution
{
public:
    string removeDuplicates(string S)
    {
        S.push_back('#');
        char reserve = S[0];
        int i = 1;
        while (true)
        {
            if (reserve == '#' && i == S.size())
            {
                break;
            }
            if (S[i] != reserve)
            {
                reserve = S[i];
                ++i;
            }
            else
            {
                S.erase(i - 1, 2);
                i = 1;
                reserve = S[0];
            }
        }
        S.pop_back();
        return S;
    }
}; */

// correct solution
class Solution
{
public:
    string removeDuplicates(string S)
    {
        string res;
        for (int i = 0; i < S.size(); i++)
        {
            if (res.empty() || res.back() != S[i])
                res.pop_back();
            else
                res.push_back(S[i]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    string S = "aaaabbcbdd";
    cout << s.removeDuplicates(S) << endl;
    return 0;
}