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
            return total == 0;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    string s1 = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60";
    cout << s.areNumbersAscending(s1) << endl;
    return 0;
}