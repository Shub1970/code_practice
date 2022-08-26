#include <iostream>
#include <vector>
#include <map>
using namespace std;
//
// class Solution
// {
// public:
// int minCostToMoveChips(vector<int> &position)
// {
// map<int, int> mp;
// for (auto it : position)
// {
// mp[it]++;
// }
// int max_val{INT32_MIN};
// int max_index{0}; // index where max chip is present
// for (auto it : mp)
// {
// cout << max_index << "=" << max_val << "\n";
// if (max_val < it.second)
// {
// max_val = it.second;
// max_index = it.first;
// }
// }
// int operation{0};
// cout << max_index;
// for (auto it : mp)
// {
// if (it.first != max_index)
// {
// if (!(max_index % 2))
// {
//
// if (it.first % 2)
// {
// operation += it.second;
// }
// }
// else
// {
// if (!(it.first % 2))
// operation += it.second;
// }
// }
// }
// return operation;
// }
// };
//
// anothe way
class Solution
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        int cnt[2] = {};
        for (auto p : chips)
            ++cnt[p % 2];
        return min(cnt[0], cnt[1]);
    }
};

int main()
{

    vector<int> position{6, 4, 7, 8, 2, 10, 2, 7, 9, 7};
    Solution obj;
    obj.minCostToMoveChips(position);
}