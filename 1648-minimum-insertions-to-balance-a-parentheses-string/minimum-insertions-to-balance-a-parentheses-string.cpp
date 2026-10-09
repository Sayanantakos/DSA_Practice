#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int neededRight = 0;

        for (char c : s) {
            if (c == '(') {
                // If neededRight is odd, insert a ')' to complete the previous '('
                if (neededRight % 2 != 0) {
                    insertions++;
                    neededRight--;
                }
                neededRight += 2;
            } else { // c == ')'
                neededRight--;
                // If neededRight falls below 0, insert a '(' before this ')'
                if (neededRight < 0) {
                    insertions++;
                    neededRight = 1;
                }
            }
        }

        return insertions + neededRight;
    }
};