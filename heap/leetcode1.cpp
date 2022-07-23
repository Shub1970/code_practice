#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        priority_queue<int> gq;
        for (auto x : nums)
        {
            gq.push(x);
        }
        int firstmax = gq.top();
        gq.pop();
        int secondmax = gq.top();
        gq.pop();

        return (firstmax - 1) * (secondmax - 1);
    }
};