#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    unordered_map<int, int> mp;
    int minOperations(vector<string> &logs)
    {
        int main_distance = 0;
        string prev_file = "";
        for (auto str : logs)
        {
            if (str == "../")
            {
                if (main_distance == 0)
                    continue;
                else
                {
                    main_distance--;
                }
            }
            else if (str == "./")
                continue;
            else
            {
                string current_file = str;
                if (prev_file != current_file)
                {
                    main_distance++;
                    prev_file = current_file;
                }
                else
                {
                    prev_file = current_file;
                }
            }
        }
        return (main_distance > 0) ? main_distance : 0;
    }
};
int main()
{
    Solution s;
    vector<string> logs = {"./", "wz4", "../", "mj2/", "../", "ik0", "i17/"};
    cout << s.minOperations(logs) << endl;
    return 0;
}