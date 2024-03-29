#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x > y)
                pq.push(x - y);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
int main()
{
    vector<int> stones{2, 7, 4, 1, 8, 1};
    Solution obj;
    cout << obj.lastStoneWeight(stones);
}