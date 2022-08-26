#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        bool result{true};
        if (target.size() == arr.size())
        {
            for (int i{0}; i < target.size(); i++)
            {
                if (target[i] != arr[i])
                    result = false;
            }
        }
        else
        {
            result = false;
        }
        return result;
    }
};
// better solution
bool canBeEqual(vector<int> &target, vector<int> &A)
{
    return unordered_multiset<int>(A.begin(), A.end()) == unordered_multiset<int>(target.begin(), target.end());
}
int main()
{
    Solution obj;
    vector<int> target{3, 7, 9}, arr{3, 7, 11};
    cout << obj.canBeEqual(target, arr);
}