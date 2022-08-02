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
    vector<bool> include;
    vector<int> weight;

public:
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
    int sortestPath(pair<int, int> src = {0, 0})
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(src);
        weight[src.second] = 0;
        while (!pq.empty())
        {
            int new_src(pq.top().second);
            pq.pop();
            cout << "weight: ";
            for (auto x : weight)
                cout << x << " ";
            cout << endl;
            cout << "include: ";
            for (auto x : include)
                cout << x << " ";
            cout << endl;
            cout << "------------------------" << endl;
            if (include[new_src])
                continue;
            include[new_src] = true;
            for (auto adjvec : graph[new_src])
            {
                if (include[adjvec.second] == false && weight[adjvec.second] > adjvec.first + weight[new_src])
                {
                    weight[adjvec.second] = adjvec.first + weight[new_src];
                    pq.push({weight[adjvec.second], adjvec.second});
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
        {2, 0, 4},
        {2, 4, 2},
        {2, 1, 4},
        {3, 4, 7},
        {4, 3, 9}};

    matrix obj(5, lis);
    cout << obj.sortestPath({0, 2});
}

// dijkstraAlgo is use to find the shortest distance from single shortest path