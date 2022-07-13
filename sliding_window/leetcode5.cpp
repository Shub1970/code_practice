#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        vector<int> char_box{0, 0, 0};
        int substr = 0;
        int first = 0;
        int end = s.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            char_box[s[i] - 'a']++;
            while (char_box[0] && char_box[1] && char_box[2])
            {
                substr += 1 + (end - i);
                char_box[s[first] - 'a']--;
                first++;
            }
        }
        return substr;
    }
};
int main()
{
    string s = "abcabc";
    Solution obj;
    cout<<obj.numberOfSubstrings(s);
    return 0;
}