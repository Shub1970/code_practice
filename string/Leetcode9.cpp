#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
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
                    prev_file = "../";
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
}; // my code giving error

// better code
// use stack to solve this problem
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;
        st.push("main");
        for (string s : logs)
        {
            if (s == "../")
            {
                if (st.top() == "main")
                {
                    st.pop();
                }
            }
            else if (s == "./")
            {
                continue;
            }
            else
            {
                st.push(s);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<string> logs = {
        "m4/",
        "p3/"
        "fy6/",
        "f3/"
        "../",
        "r2/",
        "i2/",
        "mm2/",
        "mq3/",
        "../",
        "./",
        "f3/",
        "../",
        "jz2/",
        "n8/",
        "d8/",
        "k8/",
        "../",
        "../",
    };
    cout << s.minOperations(logs) << endl;
    return 0;
}
/* ["m4/","p3/","fy6/","f3/","../","r2/","i2/","mm2/","mq3/","../","./","f3/","../","jz2/","n8/","d8/","k8/","../","../","r7/","./","f1/","a5/","./","../","../","../","jz0/","bh1/","../","ju7/","vh0/","k3/","m5/","./","m5/","./","ey8/","./","../","../","../","./","r7/","f1/","../","i7/","./","xm8/","h4/","l5/","c8/","../","g0/","m4/","xa0/","g4/","../","../","../","./","jg5/","../","../","../","e3/","t3/","ft9/","./","../","yi8/","ah3/","kc1/","j5/","../","x2/","xe6/","../","../","hn7/","./","../","../","d8/","./","../","../","c1/","../","xo7/","w3/","py7/","cf7/","../","a3/","../","./","f3/","yu6/","./","zo4/","./","../","ry3/","e4/","./","../","n2/","./","n3/","../","n2/","q9/","./","../","../","d3/","../","ot8/","y8/","i7/","jx8/","../","./","pd5/","d4/","./","v3/","s9/","s9/","qh6/","tl0/","g2/","../","../","../","k1/","../","./","../","fu7/","../","../","h0/","rp5/","./","s7/","./","./","c2/","../","w6/","./","ot2/","./","vm7/","./","../","../","ck4/","../","../","h3/","../","../","./","../","rp4/","../","./","./","./","./","../","./","qr6/","v3/","./","u4/","x3/","./","../","lm0/","q6/","./","q9/","./","v0/","../","dn9/","h8/","c2/","./","p5/","el8/","./","../","../","kk2/","il8/","dm2/","../","k6/","gy3/","c1/","../","./","./","we6/","../","px1/","./","y2/","../","q4/","s3/","./","ec9/","ih9/","rm8/","../","m5/","jv9/","x4/","ty7/","./","kz5/","c4/","hz1/","./","../","jb3/","./","./","ke3/","w4/","m3/","og9/","o8/","p1/","l3/","../","h3/","../","u1/","mx3/","./","../","z9/","./","../","./","w8/","../","./","./","gy2/","../","../","../","fg3/","ng5/","../","../","sd4/","b3/","s5/","l1/","w0/","./","../","pi6/","../","sp3/","c7/","../","../","../","i5/","./","g1/","c7/","./","u6/","w7/","./","../","./","../","./","nz1/","./","../","sx9/","n3/","../","ee7/","bs7/","dz3/","../","h7/","../","./","b8/","../","../","./","bb0/","n3/","./","n3/"] */
