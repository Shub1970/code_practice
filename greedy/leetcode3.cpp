#include <iostream>
#include <vector>
using namespace std;
// greedy about finding the position of "X" first;
class Solution
{
public:
    int minimumMoves(string s)
    {
        int count{0};
        for (int i{0}; i < s.size();)
        {
            if (s[i] == 'X')
            {
                i = i + 3;
                count++;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
};

int main()
{
    string s{"XXOX"};
    Solution obj;
    cout << obj.minimumMoves(s);
}