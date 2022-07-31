#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int partSearch(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int med{start + end >> 1};
            if (nums[med] < target)
                start = med + 1;
            else if (nums[med] > target)
                end = med - 1;
            else
                return med;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        if (nums.size() <= 1)
        {
            int ans = (nums[0] == target) ? 0 : -1;
            return ans;
        }

        int left{0}, right(nums.size() - 1);
        int pick;
        while (left <= right)
        {
            int med{left + right >> 1};
            if (nums[med] > nums[med + 1])
            {
                pick = med;
                break;
            }
            if (nums[med] > nums[left])
                left = med + 1;
            if (nums[med] < nums[right])
                right = med - 1;
        }
        cout << "pick" << pick << endl;
        int ans = partSearch(nums, 0, pick, target);
        cout << "f" << ans;
        if (ans == -1)
            ans = partSearch(nums, pick, nums.size() - 1, target);
        cout << " ans" << ans;
        return ans;
    }
};
int main()
{
    vector<int> nums{1}; //{5, 6, 7, 8, 9, 11, 13, 0, 1, 2, 3, 4};
    Solution obj;
    obj.search(nums, 0);
}