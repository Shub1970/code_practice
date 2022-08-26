#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    static bool comp(int a, int b)
    {
        int temp{14};
        int ones_a{0}, ones_b{0};
        int val{1};
        while (temp--)
        {
            if (a & val)
                ones_a++;
            if (b & val)
                ones_b++;
            val <<= 1;
        }
        return (ones_a == ones_b) ? a < b : ones_a < ones_b;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};

int main()
{
    Solution obj;
    vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ar = obj.sortByBits(arr);
    for (int it : arr)
    {
        cout << it << " ";
    }
}