// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
// iteration 1;
/* class Solution
{
    stack<int> Gstack;
    vector<int> remove_position;

public:
    void putStackValue()
    {
        while (!Gstack.empty())
        {
            remove_position.push_back(Gstack.top());
            Gstack.pop();
        }
    }

    string minRemoveToMakeValid(string s)
    {
        for (int i{0}; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                if (!Gstack.empty())
                {
                    if (s[i] == ')')
                    {
                        (s[Gstack.top()] == '(') ? Gstack.pop() : Gstack.push(i);
                    }
                    else
                    {
                        Gstack.push(i);
                    }
                }
                else
                {
                    Gstack.push(i);
                }
            }
        }
        putStackValue();
        string temp;
        for (int i{0}; i < s.size(); i++)
        {
            if (find(remove_position.begin(), remove_position.end(), i) == remove_position.end())
            {
                temp = temp + s[i];
            }
        }
        return temp;
    }
};

int main()
{
    string s = ")lee(t(c)o)de)";
    Solution obj;
    cout << obj.minRemovedToMakeValid(s);
} */

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
    }
};