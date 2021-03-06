#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
int getvalue(string word)
{
    int size = word.size();
    int wordsum = 0;
    for (char c : word)
    {
        wordsum = wordsum + (c - 'a') * pow(10, size - 1);
        ;
        --size;
    }
    cout << wordsum << endl;
    return wordsum;
}

class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        int firstWordSum = getvalue(firstWord);
        int secondWordSum = getvalue(secondWord);
        int targetWordSum = getvalue(targetWord);
        return firstWordSum + secondWordSum == targetWordSum;
    }
}; */
//---------------------------------------------------------------------------------------------------------------------
// better solution

class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        for (char &c : firstWord)
            c -= 'a' - '0';
        for (char &c : secondWord)
            c -= 'a' - '0';
        for (char &c : targetWord)
            c -= 'a' - '0';
        return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);
    }
};
int main()
{
    Solution s;
    string firstWord = "acb";
    string secondWord = "cba";
    string targetWord = "cdb";
    cout << s.isSumEqual(firstWord, secondWord, targetWord) << endl;
    return 0;
}
