#include <iostream>
#include <string>
#include <numeric>
using namespace std;
int left_side(int INIT, char num)
{
    if (num == '0')
    {
        return INIT + 1;
    }
    else
    {
        return INIT;
    }
}
int right_side(int INIT, char num)
{
    if (num == '0')
    {
        return INIT;
    }
    else
    {
        return INIT + 1;
    }
}

class Solution
{
public:
    int maxScore(string s)
    {
        int max = 0;
        for (string::iterator it = s.begin(); it != s.end() - 1; it++)
        {
            int left = accumulate(s.begin(), it, 0, left_side);
            int right = accumulate(it + 1, s.end(), 0, right_side);
            cout << left << " " << right << endl;
            if (max < left + right)
            {
                max = left + right;
            }
        }
        return max;
    }
};

int main()
{
    Solution S;
    string s = "011101";
    cout << S.maxScore(s) << endl;
}