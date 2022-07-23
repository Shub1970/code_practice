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

// better solution
int maxProduct(vector<int> &nums)
{
    auto m1{0}, m2{0};
    for (auto n : nums)
    {
        if (n > m1)
        {
            m2 = [&]()
            {int temp=m1;m1=n;return temp; }();
        }
        else
            m2 = max(m2, n);
    }
    return (m1 - 1) * (m2 - 1);
}