#include <iostream>
#include <vector>
#include <stack>
#define NIF INT32_MAX
using namespace std;
class matrix
{
    vector<vector<int>> matr;
    int row_size;
    vector<int> near;

public:
    stack<pair<int, int>> log;
    {
        matrix(vector<vector<int>> & nums) : matr{nums}, row_size{static_cast<int>(nums[0].size())} near.resize(row_size, 0);
    }
    pair<int, int> findminEdge()
    {
        pair<int, int> minEdge;
        int min{INT32_MAX};
        for (int i{0}; i < row_size; i++)
        {
            for (int j{0}; j < row_size; j++)
            {
                if (i < j)
                {
                    if (min > matr[i][j])
                    {
                        min = matr[i][j];
                        minEdge = {i, j};
                    }
                }
            }
        }
        return minEdge;
    }
    int fNextvert()
    {
        int min{INT32_MAX};
        int index{-1};
        for (int i{0}; i < row_size; i++)
        {
            if (near[i] != -1 && min > matr[i][near[i]])
            {
                min = matr[i][near[i]];
                index = i;
            }
        }
        return index;
    }
    int findMinCost()
    {
        log.push(findminEdge());
        pair<int, int> temp{log.top()};
        int minCost{matr[temp.first][temp.second]};
        for (int i{0}; i < row_size; i++)
        {
            if (matr[temp.first][i] < matr[i][temp.second])
                near[i] = temp.first;
            else
                near[i] = temp.second;
        }
        near[temp.first] = near[temp.second] = -1;
        int loop{row_size - 2};
        cout << "near" << endl;
        for (auto x : near)
            cout << x << " ";
        cout << endl;
        while (loop--)
        {
            int minVertix{fNextvert()};
            cout << "minVertix" << minVertix << endl;
            log.push({log.top().second, minVertix});
            minCost += matr[log.top().first][log.top().second];
            near[minVertix] = -1;
            for (int i{0}; i < row_size; i++)
            {
                if (near[i] != -1 && matr[minVertix][i] < matr[near[i]][i])
                    near[i] = minVertix;
            }
            for (auto x : near)
                cout << x << " ";
            cout << endl;
        }
        return minCost;
    }
};
int main()
{
    vector<vector<int>> mat{{{NIF, 9, 75, NIF, NIF},
                             {9, NIF, 95, 19, 42},
                             {75, 95, NIF, 51, 66},
                             {NIF, 19, 51, NIF, 31},
                             {NIF, 42, 66, 31, NIF}}};

    matrix obj(mat);
    // cout << "minConst"
    //  << " " << obj.findMinCost() << endl;
    obj.findMinCost();
    while (!obj.log.empty())
    {
        cout << obj.log.top().first << " " << obj.log.top().second << endl;
        obj.log.pop();
    }
}

// not properly working
