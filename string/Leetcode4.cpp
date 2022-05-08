#include <iostream>
using namespace std;
class Solution
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
                break;
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
};

int main()
{
    Solution s;
    string S = "aaaabbcbdd";
    cout << s.removeDuplicates(S) << endl;
    return 0;
}