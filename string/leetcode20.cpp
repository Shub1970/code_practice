#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string temp;
        size_t s_size{s.size()}, part_size{part.size() - 1};
        for (int i{0}, j{0}; i < s_size; i++, j++)
        {
            temp.push_back(s[i]);
            if (j >= part_size && temp.substr(j - part_size, part_size + 1) == part)
            {
                temp.resize(j - part_size);
                j -= part.size();
            }
        }
        return temp;
    }
};

int main()
{
    string s{"daabcbaabcbc"};
    string p{"abc"};
    Solution obj;
    string temp = obj.removeOccurrences(s, p);
    for (auto x : temp)
        cout << x << " ";
}