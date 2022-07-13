#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i < k - 1)
                sum += arr[i];
            else
            {
                sum += arr[i];
                if (threshold <= sum / k)
                    count++;
                sum -= arr[i - k + 1];
            }
        }
        return count;
    }
};
int main()
{
    vector<int> arr{2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3, threshold = 4;
    Solution obj;
    cout << obj.numOfSubarrays(arr, k, threshold);
}