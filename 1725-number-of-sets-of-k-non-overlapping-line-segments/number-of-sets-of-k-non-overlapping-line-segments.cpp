#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int N = n + k - 1;
        int K = 2 * k;

        // Compute combinations C(N, K) modulo 10^9 + 7 using Pascal's Triangle
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(i, K); j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }

        return dp[N][K];
    }
};