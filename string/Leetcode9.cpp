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
                cout << "str:" << str;
                if (main_distance == 0)
                {
                }
                else
                {
                    prev_file = "../";
                    main_distance--;
                }
            }
            else if (str == "./")
            {
                cout << "str:" << str;
            }
            else
            {
                cout << "str:" << str;
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
            cout << "main_distance:" << main_distance << endl;
        }
        return (main_distance > 0) ? main_distance : 0;
    }
};
int main()
{
    Solution s;
    vector<string> logs = {"./", "c1/", "pj5/", "e5/", "y6/", "../", "u4/", "a5/", "../", "nq5/", "../", "m2/", "w0/", "./", "./", "uf5/", "z8/", "../", "z8/", "r7/", "ez6/", "u4/", "it2/", "./", "../", "./", "tb9/", "o4/"};
    cout << s.minOperations(logs) << endl;
    return 0;
}
//["./","c1/","pj5/","e5/","y6/","../","u4/","a5/","../","nq5/","../","m2/","w0/","./","./","uf5/","z8/","../","z8/","r7/","ez6/","u4/","it2/","./","../","./","tb9/","o4/"]
