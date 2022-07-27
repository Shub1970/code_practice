#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{

public:
    vector<int> sorted;
    int binary_search_left(int x)
    {
        int left(0);
        int right(sorted.size() - 1);
        while (left < right)
        {
            int mid{right + left >> 1};
            if (x <= sorted[mid])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    int binary_search_right(int x)
    {
        int left{0};
        int right(sorted.size() - 1);
        while (left < right)
        {
            int mid{right + left >> 1};
            cout << mid << endl;
            if (x >= sorted[mid])
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right;
    }
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        sorted = nums;
        int left{binary_search_left(target)};
        int right{binary_search_right(target)};
        vector<int> ans;
        for (int i{left}; i <= right; i++)
        {
            ans.push_back(left++);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{24, 5, 4, 2, 2, 2, 2, 2, 2, 2, 54, 32, 15, 124, 3224, 125, 4, 54, 45, 54, 54, 54, 54, 54};
    Solution obj;
    vector<int> ans = obj.targetIndices(nums, 54);
    for (int i(0); i < nums.size(); i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto x : obj.sorted)
        cout << x << " ";
    cout << endl;
    for (auto y : ans)
        cout << y << " ";
    cout << endl;
}