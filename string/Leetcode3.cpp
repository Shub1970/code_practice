#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution
{
public:
    int minTimeToType(string word)
    {
        int initial_state = 'a';
        int seconds = 0;
        int subseconds = 0;
        for (char c : word)
        { // for clock wise c-initial_state
            // for anticlock wise 'z'-c+1+initial_state-'a'
            // for iniermidate position 'z'-initail_state+1+'c'-'a'
            subseconds = min(abs(c - initial_state), min(abs('z' - c + 1 + initial_state - 'a'), abs('z' - initial_state + 1 + c - 'a')));

            cout << "initial_state:" << initial_state << " c:" << c << " subseconds:" << subseconds << endl;
            seconds += subseconds;
            initial_state = c;
        }
        return seconds + word.size();
    }
};

int main()
{
    Solution s;
    string word = "zjpc";
    cout << s.minTimeToType(word) << endl;
    return 0;
}