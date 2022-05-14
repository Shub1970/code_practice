#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class compare1
{
    string reserve_str;

public:
    compare1(string s) : reserve_str(s){};
    bool operator()(string s1, string s2)
    {
        int i = 0;
        while (i < s1.size() && i < s2.size())
        {
            if (reserve_str.find(s1[i]) != reserve_str.find(s2[i]))
            {
                return reserve_str.find(s1[i]) < reserve_str.find(s2[i]);
            }
            i++;
        }
        return s1.size() < s2.size();
    }
};
// find will take o(n) time
// better solution will be to use map to store the order of the characters
class compare2
{
    map<char, int> order;

public:
    compare2(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            order[s[i]] = i;
        }
    }
    bool operator()(string s1, string s2)
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (order[s1[i]] != order[s2[i]])
            {
                return order[s1[i]] < order[s2[i]];
            }
        }
        return s1.size() < s2.size();
    }
};

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<string> sorted_words(words);
        compare2 cmp(order);
        sort(sorted_words.begin(), sorted_words.end(), cmp);
        for (int i = 0; i < sorted_words.size(); i++)
        {
            if (sorted_words[i] != words[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << s.isAlienSorted(words, order) << endl;
    return 0;
}