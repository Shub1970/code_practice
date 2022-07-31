#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left{0}, right(arr.size() - 1);
        while (left < right)
        {
            int mid{left + right >> 1};
            if (arr[mid] > arr[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    vector<int> arr{0, 10, 5, 2};
    Solution obj;
    cout << obj.peakIndexInMountainArray(arr);
}