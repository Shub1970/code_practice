#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;
// leetcodecom/problems/uncommon-words-from-two-sentence/
/*
class Solution
{
public:
    vector<string> uncommonFromSentence(string s1, string s2)
    {
        unordered_map<int, unordered_set<string>> mp;
        string temp;
        vector<string> result;
        for (auto ch : s1 + " ")
        {
            if (ch != ' ')
            {
                temp = temp + ch;
            }
            else
            {
                mp[temp.size()].insert(temp);
                temp = "";
            }
        }

        istringstream obs(s2);
        string te;
        while (obs >> te)
        {
            if (mp.count(te.size()))
            {
                if (mp[te.size()].end() == find(mp[te.size()].begin(), mp[te.size()].end(), te))
                {
                    result.push_back(te);
                }
            }
            else
            {
                result.push_back(te);
            }
        }
        return result;
    }
};

int main()
{
    string s1{"this apple is sweet"};
    string s2{"this apple is sour"};

    Solution obj;

    vector<string> st = obj.uncommonFromSentence(s1, s2);

    for (auto st : st)
    {
        cout << st;
    }
} */

// wrong solution

// better solution uncommon words {appear exactly once}

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        istringstream st(s1 + " " + s2);
        string arr;
        unordered_map<string, int> mp;
        vector<string> result;
        while (st >> arr)
            mp[arr]++;

        for (auto ref : mp)
        {
            if (ref.second == 1)
            {
                result.push_back(ref.first);
            }
        }
        return result;
    }
};