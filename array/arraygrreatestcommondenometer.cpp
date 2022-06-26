#include <iostream>
#include <vector>
using namespace std;
/* class Solution
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
}; */
// better way using euclidean algo.
class Solution // elucid algo......
{
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int> &nums)
    {
        int min = 1001, max = 0;
        for (int i : nums)
        {
            if (min > i)
                min = i;
            if (max < i)
                max = i;
        }
        return gcd(min, max);
    }
};
int main()
{
    Solution s;
    vector v{2, 5, 6, 9, 10};
    cout << s.findGCD(v) << endl;
}
