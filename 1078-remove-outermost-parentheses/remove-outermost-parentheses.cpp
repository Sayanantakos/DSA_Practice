#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int open = 0;

        for (char c : s) {
            if (c == '(') {
                if (open > 0) {
                    result.push_back(c);
                }
                open++;
            } else {
                open--;
                if (open > 0) {
                    result.push_back(c);
                }
            }
        }

        return result;
    }
};