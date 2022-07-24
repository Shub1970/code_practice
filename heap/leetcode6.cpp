#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        priority_queue<int> pq;
        unordered_map<int, int> mp;
        for (auto m : arr)
            mp[m]++;
        for (auto x : mp)
            pq.push(x.second);
        int max_size = arr.size();
        int half_size = max_size / 2;
        int no_of_chose = 0;
        while (!(max_size <= half_size))
        {
            max_size -= pq.top();
            no_of_chose++;
            pq.pop();
        }
        return no_of_chose;
    }
};

int main()
{
    vector<int> nums{3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    Solution obj;
    cout << obj.minSetSize(nums);
}