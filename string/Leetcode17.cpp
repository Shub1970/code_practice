#include <iostream>
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    int secondHigest(string s)
    {
        set<int> int_set;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int_set.insert(s[i] - '0');
            }
        }
        auto it = int_set.rbegin();
        if (int_set.size() < 1)
        {
            return -1;
        }
        else
        {
            return *(--it);
        }
    }
};
int main()
{
    Solution s;
    string s1 = ""kwvfiprlqymptsmmrfd199114918818919414"f";
    cout << s.secondHigest(s1) << endl;
    return 0;
}
