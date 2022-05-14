#include <iostream>
#include <string>
using namespace std;
class Solutino
{
public:
    string thousandSeparator(int n)
    {
        string st = to_string(n);
        int len = st.length();
        string res = "";
        for (int i = 0; i < len; i++)
        {
            if (i > 0 && (st.size() - i) % 3 == 0)
            {
                res = ;
            }
            res += st[i];
        }
    }
};
int main()
{
    Solutino s;
    cout << s.thousandSeparator(12334562) << endl;
    return 0;
}