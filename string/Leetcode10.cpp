#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* class Solution
{
public:
    int convertTime(string current, string correct)
    {
        vector<int> greedy;
        int operation = 0;
        int minute = stoi(current.substr(3, 2));
        int hour = stoi(current.substr(0, 2));
        int minute_correct = stoi(correct.substr(3, 2));
        int hour_correct = stoi(correct.substr(0, 2));
        int minute_diff = minute_correct - minute;
        int hour_diff = hour_correct - hour;
        int level = 0;
        if (minute_diff >= 0)
        {
            level = minute_diff;
        }
        else
        {
            operation = 1;
            hour_diff--;
            level = 60 - minute + minute_correct;
        }
        int marker = 0;
        while (true)
        {
            if (level != marker)
            {
                if (level - marker >= 30)
                {
                    marker = marker + 30;
                    operation++;
                }
                else if (level - marker >= 15)
                {
                    operation++;
                    marker = marker + 15;
                }
                else if (level - marker >= 10)
                {
                    marker = marker + 10;
                    operation++;
                }
                else if (level - marker >= 5)
                {
                    marker = marker + 5;
                    operation++;
                }
                else
                {
                    operation++;
                    marker = marker + 1;
                }
            }
            else
            {
                break;
            }
        }
        return operation + hour_diff;
    }
}; */
// not able to solve
class Solution
{
    int getTime(string &s)
    {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }

public:
    int convertTime(string current, string correct)
    {
        int diff = getTime(current) - getTime(correct), ops[4]{60, 15, 5, 1}, ans = 0;
        for (int op : ops)
        {
            ans += diff / op;
            diff %= op;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string current = "06:50";
    string correct = "12:47";
    cout << s.convertTime(current, correct) << endl;
    return 0;
}