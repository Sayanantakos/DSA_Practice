#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        auto isPalindrome = [&](int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) return false;
                left++;
                right--;
            }
            return true;
        };

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i >= k && isPalindrome(i - k, i - 1)) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }
            if (i >= k + 1 && isPalindrome(i - k - 1, i - 1)) {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }

        return dp[n];
    }
};