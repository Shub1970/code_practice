#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

class Solution
{
    vector<bool> include;
    vector<int> weight;

public:
    template <typename T>
    int disCalc(T &p, T &q)
    {
        return abs(abs(p[0] - q[0]) + abs(p[1] - q[1]));
    }
    int minCostConnectPoints(vector<vector<int>> &points, pair<int, int> src = {0, 0})
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        include.resize(points.size(), false);
        weight.resize(points.size(), INT32_MAX);
        pq.push(src);
        weight[src.second] = src.first;
        while (!pq.empty())
        {
            int new_src(pq.top().second);
            pq.pop();
            if (include[new_src])
                continue;
            include[new_src] = true;
            // cout << "weight: ";
            // for (auto x : weight)
            // cout << x << " ";
            // cout << endl;
            // cout << "include: ";
            // for (auto x : include)
            //  cout << x << " ";
            // cout << endl;
            // cout << "------------------------" << endl;
            int i{0};
            for (auto point : points)
            {
                int tempDist = disCalc(points[new_src], point);
                if (include[i] == false && weight[i] > tempDist)
                {
                    weight[i] = tempDist;
                    pq.push({tempDist, i});
                }
                i++;
            }
        }
        return accumulate(weight.begin(), weight.end(), 0);
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    obj.minCostConnectPoints(points);
}