// https://leetcode.com/problems/score-of-parentheses/discuss/1856699/C%2B%2B-BEATS-100-OMG!!!-(-%22-)-O(1)-Space-Explained
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>

using namespace std;
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int ans{0};
        stack<string> sta;
        int i{0};
        while (i < s.length())
        {
            if (s[i] == '(')
                sta.push("(");
            else
            {
                if (sta.top() == "(")
                {
                    sta.pop();
                    sta.push("1");
                }
                else
                {
                    int count{0};
                    while (sta.top() != "(")
                    {
                        count += stoi(sta.top());
                        sta.pop();
                    }
                    sta.pop();
                    sta.push(to_string(2 * count));
                }
            }
            i++;
        }
        while (!sta.empty())
        {
            ans += stoi(sta.top());
            sta.pop();
        }
        return ans;
    }
};

//        "(((())())())"   string

// |    |
// |    |
// | 1  |
// | 1  |
// | (  |           stack
// | (  |
// | (  |
// |----|

// better solution
//  ()() => 1+1
//  (()()) => 2*(1+1)
//  ((()())) => 2*2*(1+1)
//  ((()(()))) => 2*2*(1+2*1)

// We can see that any () in the string gives a score depending on its depth. If () is located on the higher possible level (depth=0), the score is simply a 1. If it's located deeper, we just multiply it by 2 as many times as its depth. The found score we can just add to the final result. Why can we do that? Remember that, for example, this expression 2*2*(1+1) can be expressed as 2*2+2*2. No matter how deep parenthesis, the final expression of score can be represented as a sum of () scores.

// Time: O(N) - traversing
// Space: O(1) - OMAGAD!!! (´▽`ʃƪ)

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Score of Parentheses.
// Memory Usage: 6.1 MB, less than 83.25% of C++ online submissions for Score of Parentheses
//================================================================================================================================================
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int depth = 0, res = 0;
        char prev = '(';

        for (const char &ch : s)
        {
            if (ch == '(')
                depth++;
            else
            {
                depth--;
                if (prev == '(')
                    res += pow(2, depth);
            }

            prev = ch;
        }

        return res;
    }
};