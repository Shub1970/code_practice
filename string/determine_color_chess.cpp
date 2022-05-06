#include <iostream>
using namespace std;

class Solution
{
public:
    bool sqareIsWhite(string coordinates)
    {
        int x = coordinates[0] - 'a' + 1;
        int y = coordinates[1] - '1' + 1;
        if (x % 2 == 0)
        {
            if (y % 2 != 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (y % 2 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
int main()
{
    Solution s;
    cout << s.sqareIsWhite("a1") << endl;
    cout << s.sqareIsWhite("h3") << endl;
    cout << s.sqareIsWhite("c7") << endl;
    cout << s.sqareIsWhite("b2") << endl;
    return 0;
}
