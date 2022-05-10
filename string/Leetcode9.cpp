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
//["m4/","p3/","fy6/","f3/","../","r2/","i2/","mm2/","mq3/","../","./","f3/","../","jz2/","n8/","d8/","k8/","../","../","r7/","./","f1/","a5/","./","../","../","../","jz0/","bh1/","../","ju7/","vh0/","k3/","m5/","./","m5/","./","ey8/","./","../","../","../","./","r7/","f1/","../","i7/","./","xm8/","h4/","l5/","c8/","../","g0/","m4/","xa0/","g4/","../","../","../","./","jg5/","../","../","../","e3/","t3/","ft9/","./","../","yi8/","ah3/","kc1/","j5/","../","x2/","xe6/","../","../","hn7/","./","../","../","d8/","./","../","../","c1/","../","xo7/","w3/","py7/","cf7/","../","a3/","../","./","f3/","yu6/","./","zo4/","./","../","ry3/","e4/","./","../","n2/","./","n3/","../","n2/","q9/","./","../","../","d3/","../","ot8/","y8/","i7/","jx8/","../","./","pd5/","d4/","./","v3/","s9/","s9/","qh6/","tl0/","g2/","../","../","../","k1/","../","./","../","fu7/","../","../","h0/","rp5/","./","s7/","./","./","c2/","../","w6/","./","ot2/","./","vm7/","./","../","../","ck4/","../","../","h3/","../","../",".
