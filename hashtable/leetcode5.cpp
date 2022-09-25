#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int temp(1);
        for (auto x : nums)
        {
            if (temp == x)
            {
                break;
            }
            else
            {
                temp = x;
            }
        }
        return { temp, temp + 1 }
    }
};