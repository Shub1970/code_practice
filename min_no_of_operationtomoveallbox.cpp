/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.



Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        const int siz = boxes.size();
        vector<int> answer(siz, 0);
        for (int i = 0; i < siz; i++)
        {
            for (int j = 0; j < siz; j++)
            {
                if (boxes[j] == '1')
                {
                    answer[i] = answer[i] + abs(i - j);
                }
            }
        }
        return answer;
    }
};

//opetimize
/*
Optimized
class Solution {
public:
    vector<int> ans ;
    vector<int> minOperations(string boxes) {
        int ones = 0 ;
        int temp = 0 ; 
        for(int i = 0 ; i < boxes.size() ; ++i ){
            ans.push_back(temp) ;
            ones += boxes[i]-'0' ;
            temp += ones ;
        }
        ones = temp = 0 ;
        for(int i = boxes.size() - 1 ; i >=0 ; --i ){
            ans[i] += temp ;;
            ones += boxes[i]-'0' ;
            temp += ones ;
        }
        return ans ;
        
    }
};
*/

int main()
{
    string st = "001011";
    Solution s;
    vector<int> ans = s.minOperations(st);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}
