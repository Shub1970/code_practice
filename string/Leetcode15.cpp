// minimum-moves-to-convert-string
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solve(string &s)
{
    int operations = 0;
    for (int i = 2; i < s.size(); i = i + 3)
    {
        if (s[i - 2] == 'X' || s[i - 1] == 'X' || s[i] == 'X')
        {
            operations++;
        }
    }
    return operations;
}

class Solution
{
public:
    int minimumMoves(string s)
    {
        int operation = 0;
        string::iterator it = s.begin();
        while (it < s.end())
        {
            string::iterator X_position;
            X_position = find(it, s.end(), 'X');
            it = X_position;
            if (X_position != s.end())
            {
                operation++;
                *X_position = *(X_position + 1) = *(X_position + 2) = 'O';
            }
        }

        return operation;
    }
};

int main()
{
    Solution S;
    string s = "OXOX";
    cout << S.minimumMoves(s) << endl;
}