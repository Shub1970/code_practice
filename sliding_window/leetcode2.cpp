#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> nmap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nmap.count(nums[i] == 0))
                nmap[nums[i]] = i;
            else if (i - nmap[nums[i]] <= k)
                return 1;
            else
            {
                nmap[nums[i]] = 1;
            }
        }
        return 0;
    }
};
int main()
{
    vector<int> nums{1, 2, 3, 1, 2, 3};
    int k = 2;
    Solution obj;
    cout << obj.containsNearbyDuplicate(nums, k);
    return 0;
}