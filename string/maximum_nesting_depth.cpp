#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        // it is guaranteed that parentheses expression si a VPS
        int depth = 0;
        int max_depth = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                depth++;
            }
            else if (c == ')')
            {
                depth--;
            }
            max_depth = max(max_depth, depth);
        }
        return max_depth;
    }
};

int main()
{
    Solution s;
    cout << s.maxDepth("(()())") << endl;
    return 0;
}