#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> KWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<int, int>> pq; // still showing problem when value is same
        vector<int> ans;
        for (int i = 0; i < mat.size(); i++)
        {
            int onescount = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j])
                    onescount += mat[i][j];
                else
                    break;
            }
            pq.push({-onescount, -i});
        }
        for (int i = 0; i < k; i++)
        {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(-temp.second);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> mat{{1, 1, 0, 0, 0},
                            {1, 1, 1, 1, 0},
                            {1, 0, 0, 0, 0},
                            {1, 1, 0, 0, 0},
                            {1, 1, 1, 1, 1}};
    Solution obj;
    vector<int> ans = obj.KWeakestRows(mat, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}