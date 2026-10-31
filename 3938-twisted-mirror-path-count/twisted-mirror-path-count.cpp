#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 1000000007;

    struct Landing {
        int r, c;
        bool valid;
    };

    Landing getLanding(const vector<vector<int>>& grid, int r, int c, int dir, int m, int n, vector<vector<vector<Landing>>>& memo) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return {-1, -1, false};
        }

        if (grid[r][c] == 0) {
            return {r, c, true};
        }

        if (memo[r][c][dir].r != -2) {
            return memo[r][c][dir];
        }

        Landing res;
        if (dir == 0) { // Entered moving Right -> turned Down -> next is (r + 1, c) entered Down (1)
            res = getLanding(grid, r + 1, c, 1, m, n, memo);
        } else {        // Entered moving Down -> turned Right -> next is (r, c + 1) entered Right (0)
            res = getLanding(grid, r, c + 1, 0, m, n, memo);
        }

        return memo[r][c][dir] = res;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Memoization table for mirror reflections
        vector<vector<vector<Landing>>> memo(m, vector<vector<Landing>>(n, vector<Landing>(2, {-2, -2, false})));

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;

        for (int r = m - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (grid[r][c] != 0) {
                    continue;
                }
                if (r == m - 1 && c == n - 1) {
                    continue;
                }

                int totalPaths = 0;

                // Move Right -> target (r, c + 1) entered Right (dir = 0)
                Landing landR = getLanding(grid, r, c + 1, 0, m, n, memo);
                if (landR.valid) {
                    totalPaths = (totalPaths + dp[landR.r][landR.c]) % MOD;
                }

                // Move Down -> target (r + 1, c) entered Down (dir = 1)
                Landing landD = getLanding(grid, r + 1, c, 1, m, n, memo);
                if (landD.valid) {
                    totalPaths = (totalPaths + dp[landD.r][landD.c]) % MOD;
                }

                dp[r][c] = totalPaths;
            }
        }

        return dp[0][0];
    }
};