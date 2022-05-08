#include <iostream>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string S)
    {
        char reserve = S[0];
        int i = 1;
        while (true)
        {
            if (i == S.size() - 1)
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
        return S;
    }
};

int main()
{
    Solution s;
    string S = "azxxzy";
    cout << s.removeDuplicates(S) << endl;
    return 0;
}