#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> matri;
    int row{0}, coloum{0}, ans{-1};

public:
    int countlessthanx(int x)
    {
        int count{0};
        for (int r{0}; r < row; r++)
        {
            int c{coloum - 1};
            for (c; matri[r][c] > x; c--)
                continue;
            count += (c + 1);
        }
        return count;
    }
    int KthLargestValue(vector<vector<int>> &matrix, int k)
    {
        matri = move(matrix);
        row = matri.size();
        coloum = matri[0].size();
        int left{matri[0][0]}, right{matri[row - 1][coloum - 1]};
        while (left <= right)
        {
            int med{left + right >> 1};
            if (countlessthanx(med) >= k)
            {
                ans = med;
                right = med - 1;
            }
            else
                left = med + 1;
        }
    }
};
matrix = [[1,5,9],[10,11,13],[12,13,15]]
