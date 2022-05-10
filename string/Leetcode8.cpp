#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Solution
{
    vector<int> nums;

public:
    bool test_no_repeat_integers(vector<int> &nums)
    {
        int temp = -1;
        for (auto t : nums)
        {
            if (t == temp)
            {
                return false;
            }
            temp = t;
        }
        return true;
    }
    bool areNumbersAscending(string s)
    {

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                if (isdigit(s[i + 1]))
                {
                    nums.push_back(stoi(s.substr(i, 2)));
                    i++;
                }
                else
                {
                    nums.push_back(stoi(s.substr(i, 1)));
                }
            }
        }
        for (auto t : nums)
        {
            cout << t << " ";
        }
        cout << endl;
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        for (auto s : temp)
        {
            cout << s << " ";
        }
        cout << endl;
        int total = 0;
        if (test_no_repeat_integers(temp))
        {
            cout << "true" << endl;

            int total = inner_product(nums.begin(), nums.end(), temp.begin(), 0, plus<int>(), equal_to<int>());
            cout << "total:" << total << endl;
            return total == nums.size();
        }
        else
        {
            return false;
        }
    }
};

// better solution
class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int prev = 0;
        int curr = 0;
        for (auto ch : s)
        {
            if (isdigit(ch))
            {
                curr = curr * 10 + ch - '0';
            }
            else if (curr != 0)
            {
                if (prev >= curr)
                {
                    return false;
                }
                prev = curr;
                curr = 0;
            }
        }
        return curr == 0 || prev < curr;
    }
};
int main()
{
    Solution s;
    string s1 = "1 box has 3 blue 4 red 6 green and 12 yellow balls";
    cout << s.areNumbersAscending(s1) << endl;
    return 0;
}