/* 2114. Maximum Number of Words Found in Sentences
        Easy

    520

    19

    Add to List

        Share
            A sentence is a list of words that are separated by a single space with no leading or
    trailing spaces.

    You are given an array of strings sentences,
    where each sentences[i] represents a single sentence.

    Return the maximum number of words that appear in a single sentence.

    Example 1 :

    Input : sentences = [ "alice and bob love leetcode", "i think so too", "this is great thanks very much" ] Output : 6 Explanation : -The first sentence,
            "alice and bob love leetcode", has 5 words in total.- The second sentence, "i think so too", has 4 words in total.- The third sentence, "this is great thanks very much", has 6 words in total.Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words. */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int max = 0;
        for (string subsentences : sentences)
        {
            int submax = 0;
            int subsubmax = 0;
            for (size_t i = 0; i < subsentences.size(); i++)
            {
                if (subsentences[i] != ' ')
                {
                    ++subsubmax;
                }
                else
                {
                    if (subsubmax > submax)
                    {
                        submax = subsubmax;
                    }
                    subsubmax = 0;
                    continue;
                }
            }
            if (submax > max)
            {
                max = submax;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<string> sentences;
    sentences.push_back("ajidfjakjfi ijijoib ojiojijojioj");
    sentences.push_back("ajidfjakjfijijfi ijijoib ojiojijojioj kafjdiawejf");
    int max = s.mostWordsFound(sentences);
    cout << max << endl;
}