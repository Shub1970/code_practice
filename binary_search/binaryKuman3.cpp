#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// what if array is infinit and you want to find the position of element

// we are going to do block linear search, but block is going to grow log();

// start with the box of size 2

pair<int, int> find_range(vector<int> &arr, int target)
{
    // first find the range
    // first start whith size 2

    int start{0}, end{1};
    while (target > arr[end])
    {
        int temp = end + 1;
        // double the box value
        end = end + 2 * (end - start + 1);
        start = temp;
    }
    // then do binary search on the box

    auto ans = equal_range(arr.begin() + start, arr.begin() + end, target);
}