#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

// how to solve(we are going to be greedy about two candy whose min cost is going to big enough so that we can chose maximum candy from which we are going to pick most costly)
class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.begin(), cost.end(), greater<int>());
        list<int> ls;
        for (auto x : cost)
            ls.push_back(x);
        int totalCost{0};
        while (!ls.empty())
        {
            if (ls.size() <= 1)
            {
                return totalCost += *ls.begin();
            }
            auto it = ls.begin();
            int minCostCand = *(++it);
            totalCost += (*(ls.begin()) + *(it));
            ls.erase(ls.begin());
            ls.erase(it);
            for (auto its{ls.begin()}; its != ls.end(); its++)
            {
                if (*its <= minCostCand)
                {
                    ls.erase(its);
                    break;
                }
            }
        }
        return totalCost;
    }
};

// better solutioin
int minimumCost(vector<int> &cost)
{
    int res = 0;
    sort(rbegin(cost), rend(cost));
    for (int i = 0; i < cost.size(); ++i)
        res += i % 3 == 2 ? 0 : cost[i];
    return res;
}

int main()
{
    Solution obj;
    vector<int> ls{3, 3, 3, 1};
    cout << obj.minimumCost(ls);
}