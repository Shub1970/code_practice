#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int largestInteger(int num)
    {
        string ans;
        vector<int> arra;
        priority_queue<int> odd;
        priority_queue<int> even;
        int temp = num;
        while (temp)
        {
            int tempInt = temp % 10;
            (tempInt & 1) ? odd.push(tempInt) : even.push(tempInt);
            arra.push_back(tempInt);
            temp /= 10;
        }
        reverse(arra.begin(), arra.end());
        for (auto &x : arra)
        {
            if (x & 1)
            {
                x = odd.top();
                odd.pop();
            }
            else
            {
                x = even.top();
                even.pop();
            }
            ans += to_string(x);
        }
        return stoi(ans);
    }
};
int main()
{
    int num = 1234;
    Solution obj;
    cout << obj.largestInteger(num);
}