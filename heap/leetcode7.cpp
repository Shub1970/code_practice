#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> KClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, pair<int, int>>> pq;
        vector<vector<int>> ret;
        for (auto x : points)
        {
            double dist = pow(pow(x[0], 2) + pow(x[1], 2), 0.5);
            pq.push({-dist, {x[0], x[1]}});
        }
        while (k--)
        {
            auto temp = pq.top().second;
            pq.pop();
            cout << temp.first << " ";
            ret.push_back({temp.first, temp.second});
        }
        cout << endl;
        return ret;
    }
};

// complexity creating queue o(n);

int main()
{
    int k = 2;
    vector<vector<int>> points{{3, 3}, {5, -1}, {-2, 4}};
    Solution obj;

    auto ret = obj.KClosest(points, k);
    cout << "[ ";
    for (auto x : ret)
    {
        cout << "[ " << x[0] << "," << x[1] << " ]";
    }
    cout << " ]" << endl;
}