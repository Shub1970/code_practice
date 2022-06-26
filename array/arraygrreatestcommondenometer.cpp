#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int min = 1001, max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (min > nums[i])
            {
                min = nums[i];
            }
            if (max < nums[i])
            {
                max = nums[i];
            }
        }
        int gcd = 1;
        for (int i = min; i > 0; i--)
        {
            if (!(min % i) && !(max % i))
            {
                gcd = i;
                break;
            }
        }
        return gcd;
    }
};
int main()
{
    Solution s;
    vector v{2, 5, 6, 9, 10};
    cout << s.findGCD(v) << endl;
}
