#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<string> validStrings;

    void backtrack(const string& s, int index, int openCount, int remL, int remR, string& current) {
        if (index == s.length()) {
            if (remL == 0 && remR == 0 && openCount == 0) {
                validStrings.insert(current);
            }
            return;
        }

        char c = s[index];

        // Option 1: Remove current character
        if (c == '(' && remL > 0) {
            backtrack(s, index + 1, openCount, remL - 1, remR, current);
        } else if (c == ')' && remR > 0) {
            backtrack(s, index + 1, openCount, remL, remR - 1, current);
        }

        // Option 2: Keep current character
        if (c != '(' && c != ')') {
            current.push_back(c);
            backtrack(s, index + 1, openCount, remL, remR, current);
            current.pop_back();
        } else if (c == '(') {
            current.push_back(c);
            backtrack(s, index + 1, openCount + 1, remL, remR, current);
            current.pop_back();
        } else if (c == ')' && openCount > 0) {
            current.push_back(c);
            backtrack(s, index + 1, openCount - 1, remL, remR, current);
            current.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int remL = 0;
        int remR = 0;

        for (char c : s) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) {
                    remL--;
                } else {
                    remR++;
                }
            }
        }

        string current = "";
        backtrack(s, 0, 0, remL, remR, current);

        return vector<string>(validStrings.begin(), validStrings.end());
    }
};