#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int minPrev = dp[i - 1] + 1;

            if (i >= 2) {
                minPrev = min(minPrev, dp[i - 2] + 4);
            }
            if (i >= 3) {
                minPrev = min(minPrev, dp[i - 3] + 9);
            }

            dp[i] = minPrev + costs[i - 1];
        }

        return dp[n];
    }
};