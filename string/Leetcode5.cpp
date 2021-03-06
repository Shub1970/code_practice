#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define max_size 100000
using namespace std;
class Solution
{
    int find_best_range(vector<pair<int, int>> &v, int index)
    {
        int ans = 0;
        for (auto p : v)
        {
            if (p.first <= index && index <= p.second)
            {
                ans = (abs(p.first - index) < abs(p.second - index)) ? p.first : p.second;
            }
        }
        return ans;
    }

public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> ans(S.size(), 0);
        vector<pair<int, int>> range;
        int first = -10000;
        int last = max_size;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                if (last == max_size)
                {
                    last = i;
                }
                else
                {
                    first = last;
                    last = i;
                }
                range.push_back(make_pair(first, last));
            }
            else
            {
                if (i == S.size() - 1)
                {
                    first = last;
                    last = 10000;
                    range.push_back(make_pair(first, last));
                }
            }
        }
        for (int i = 0; i < S.size(); i++)
        {
            ans[i] = abs(i - find_best_range(range, i));
        }
        return ans;
    }
};
//-----------------------------------------------------------------------------
// better solution
/* class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        int n = S.size();
        int pos = -n;
        vector<int> ans(n, n);
        for (int i = 0; i < n; i++)
        {
            if (S[i] == C)
            {
                pos = i;
            }
            ans[i] = i - pos;
        }
        for (int i = 0; i < n; --i)
        {
            if (S[i] == C)
            {
                pos = i;
            }
            ans[i] = min(ans[i], pos - i);
        }
        return ans;
    }
}; */
int main()
{
    Solution s;
    string S = "aaba";
    char C = 'b';
    vector<int> ans = s.shortestToChar(S, C);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}