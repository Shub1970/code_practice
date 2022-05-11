// minimum-moves-to-convert-string
#include <iostream>
#include <string>
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
        if (!s.size() % 3)
        {
            operation = solve(s);
            cout << "0" << s << endl;
        }
        else if (s.size() % 3 == 1)
        {
            s.push_back('O');
            s.push_back('O');
            cout << "1" << s << endl;
            operation = solve(s);
        }
        else if (s.size() % 3 == 2)
        {
            s.push_back('O');
            cout << "2" << s << endl;
            operation = solve(s);
        }
        return operation;
    }
};

int main()
{
    Solution S;
    string s = "XXOOXXX";
    cout << S.minimumMoves(s) << endl;
}