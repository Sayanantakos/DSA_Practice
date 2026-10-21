#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        // 1. Check if s is already sorted
        bool isSorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] > s[i + 1]) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) {
            return 0;
        }

        // 2. Length 2 unsorted string cannot be sorted
        if (n == 2) {
            return -1;
        }

        // 3. Find global min and max characters
        char minChar = s[0];
        char maxChar = s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] < minChar) minChar = s[i];
            if (s[i] > maxChar) maxChar = s[i];
        }

        char firstChar = s[0];
        char lastChar = s[n - 1];

        // 4. 1 operation if min is at start or max is at end
        if (firstChar == minChar || lastChar == maxChar) {
            return 1;
        }

        // 5. Check if minChar exists in s[0..n-2] or maxChar exists in s[1..n-1]
        bool minInPrefix = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == minChar) {
                minInPrefix = true;
                break;
            }
        }

        bool maxInSuffix = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == maxChar) {
                maxInSuffix = true;
                break;
            }
        }

        // 6. 3 operations required ONLY if max is strictly at start, min is strictly at end,
        // and neither appears anywhere in the interior
        if (firstChar == maxChar && lastChar == minChar && !minInPrefix && !maxInSuffix) {
            return 3;
        }

        // 7. 2 operations for all remaining cases
        return 2;
    }
};