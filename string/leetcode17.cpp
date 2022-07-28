#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<int> ansv;

public:
    vector<int> executeInstructions(int n, vector<int> &start, string s)
    {
        if (s.size() == 0)
        {
            return ansv;
        }
        int ans = 0, row{start[0]}, col{start[1]};
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                col--;
            else if (s[i] == 'R')
                col++;
            else if (s[i] == 'U')
                row--;
            else
                row++;
            if (row < 0 || col < 0 || row >= n || col >= n)
            {
                ansv.push_back(ans);
                return executeInstructions(n, start, s.erase(0, 1));
            }

            ans++;
        }
        ansv.push_back(ans);
        return executeInstructions(n, start, s.erase(0, 1));
    }
};

int main()
{
    string s = "RRDDLU";
    int n = 3;
    vector<int> start{0, 1};
    Solution obj;
    vector<int> ans = obj.executeInstructions(n, start, s);
    for (auto x : ans)
        cout << x << " ";
}