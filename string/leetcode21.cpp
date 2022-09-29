#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> res;
        string tem_st{""};
        sort(products.begin(), products.end());
        for (auto ch : searchWord)
        {
            tem_st.push_back(ch);
            vector<string> temp;
            int j{3};
            for (int i{0}; i < products.size(); i++)
            {
                if (products[i].substr(0, tem_st.size()) == tem_st)
                {
                    temp.push_back(products[i]);
                    j--;
                }
            }
            if (temp.size() > 3)
            {
                while (temp.size() != 3)
                {
                    temp.pop_back();
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};
int main()
{
    vector<string> products{"havana"};
    string searchWord{"havana"};
    Solution obj;
    obj.suggestedProducts(products, searchWord);
}