#include <string>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i - 1] == 'b' && s[i] == 'a') {
                return false;
            }
        }
        return true;
    }
};