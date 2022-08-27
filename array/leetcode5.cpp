#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int parameter{0};
        for (int i{0}; i < grid.size(); i++)
        {
            for (int j{0}; j < grid[0].size(); j++)
            {
                int temp{4};
                if (grid[i][j])
                {
                    (i - 1 >= 0 && grid[i - 1][j]) ? temp-- : 0;
                    (i + 1 <= (grid.size() - 1) && grid[i + 1][j]) ? temp-- : 0;
                    (j - 1 >= 0 && grid[i][j - 1]) ? temp-- : 0;
                    (j + 1 <= (grid[0].size() - 1) && grid[i][j + 1]) ? temp-- : 0;
                    parameter += temp;
                }
                // cout << "{" << i << "," << j << "}" << temp << "\n";
            }
        }
        return parameter;
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> grid{{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << obj.islandPerimeter(grid);
}