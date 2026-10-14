#include <string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int count9 = sum / 9;
        int rem = sum % 9;
        int needed = count9 + (rem > 0 ? 1 : 0);

        // Impossible if required digits exceed allowed length
        if (needed > num) {
            return "";
        }

        string result = "";
        result.reserve(num);

        // Place maximum possible '9's, remainder digit, and trailing '0's
        result.append(count9, '9');
        if (rem > 0) {
            result += to_string(rem);
        }
        result.append(num - needed, '0');

        return result;
    }
};