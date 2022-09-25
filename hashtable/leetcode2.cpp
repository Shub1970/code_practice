#include <iostream>
#include <string.h>
using namespace std;
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
        {
            return true;
        }
        else
        {
            for (int i{0}; i < s1.size(); i++)
            {
                for (int j{i}; j < s1.size(); j++)
                {
                    string temp(s1);
                    auto tem = move(temp[i]);
                    temp[i] = move(temp[j]);
                    temp[j] = move(tem);
                    if (temp == s2)
                        return true;
                    else
                        continue;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    string s1{"bank"}, s2{"kanb"};
    cout << obj.areAlmostEqual(s1, s2);
}