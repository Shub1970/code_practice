#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <queue>
#define INF INT32_MAX
using namespace std;
class matrix
{
    int vertex;
    vector<list<pair<int, int>>> graph;

public:
    vector<bool> include;
    vector<int> weight;
    matrix(int _vertex, vector<vector<int>> lis) : vertex(_vertex)
    {
        graph.resize(vertex);
        include.resize(vertex, false);
        weight.resize(vertex, INT32_MAX);
        for (auto edg : lis)
        {
            graph[edg[0]].push_back({edg[2], edg[1]});
        }
    }
    void show()
    {
        int i{0};
        for (auto li : graph)
        {
            cout << i;
            for (auto it : li)
            {
                cout << " :{" << it.first << "," << it.second << "} ";
            }
            cout << endl;
            i++;
        }
    }
    int minCost(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        weight[src] = 0;
        while (!pq.empty())
        {
            int new_src = pq.top().second;
            pq.pop();
            cout << new_src << ":";
            for (auto x : include)
                cout << x << " ";
            cout << endl;
            if (include[new_src])
                continue;
            include[new_src] = true;
            for (auto x : graph[new_src])
            {
                if (include[x.second] == false && weight[x.second] > x.first)
                {
                    weight[x.second] = x.first;
                    pq.push(x);
                }
            }
        }
        return accumulate(weight.begin(), weight.end(), 0);
    }
};
int main()
{
    vector<vector<int>> lis{
        {0, 1, 10},
        {0, 2, 3},
        {1, 3, 2},
        {1, 2, 1},
        {2, 3, 8},
        {2, 4, 2},
        {2, 1, 4},
        {3, 4, 7},
        {4, 3, 9}};
    matrix obj(5, lis);
    cout << obj.minCost(0) << endl;
    for (auto x : obj.weight)
        cout << x << " ";
}
