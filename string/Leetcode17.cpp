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
        for (auto i : int_set)
        {
            cout << i << " ";
        }
        cout << endl;
        auto it = int_set.rbegin();
        if (int_set.size() < 2)
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
    string s1 = "abc1111";
    cout << s.secondHigest(s1) << endl;
    return 0;
}