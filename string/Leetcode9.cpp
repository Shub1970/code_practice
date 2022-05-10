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
        int prev_file_no = 0;
        for (auto str : logs)
        {
            if (str == "../")
            {
                main_distance--;
            }
            else if (str[0] == 'd')
            {
                int current_file_no = stoi(str.substr(1, str.size() - 1));
                if (prev_file_no != current_file_no)
                {
                    main_distance++;
                    prev_file_no = current_file_no;
                    ;
                }
                else
                {
                    prev_file_no = current_file_no;
                }
            }
        }
        return (main_distance > 0) ? main_distance : 0;
    }
};
int main()
{
    Solution s;
    vector<string> logs = {"d1/", "../", "../", "../"};
    cout << s.minOperations(logs) << endl;
    return 0;
}