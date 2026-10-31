import java.util.Arrays;

class Solution {
    private static final int MOD = 1_000_000_007;

    public int uniquePaths(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // Memoization table for mirror reflections: memo[r][c][dir]
        // dir = 0 (Right), dir = 1 (Down)
        int[][][] memoR = new int[m][n][2];
        int[][][] memoC = new int[m][n][2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(memoR[i][j], -2);
                Arrays.fill(memoC[i][j], -2);
            }
        }

        int[][] dp = new int[m][n];
        dp[m - 1][n - 1] = 1;

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (grid[r][c] != 0) {
                    continue;
                }
                if (r == m - 1 && c == n - 1) {
                    continue;
                }

                int totalPaths = 0;

                // Move Right -> target (r, c + 1) entered moving Right (dir = 0)
                int[] landR = getLanding(grid, r, c + 1, 0, m, n, memoR, memoC);
                if (landR != null) {
                    totalPaths = (totalPaths + dp[landR[0]][landR[1]]) % MOD;
                }

                // Move Down -> target (r + 1, c) entered moving Down (dir = 1)
                int[] landD = getLanding(grid, r + 1, c, 1, m, n, memoR, memoC);
                if (landD != null) {
                    totalPaths = (totalPaths + dp[landD[0]][landD[1]]) % MOD;
                }

                dp[r][c] = totalPaths;
            }
        }

        return dp[0][0];
    }

    private int[] getLanding(int[][] grid, int r, int c, int dir, int m, int n, int[][][] memoR, int[][][] memoC) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return null;
        }

        if (grid[r][c] == 0) {
            return new int[]{r, c};
        }

        if (memoR[r][c][dir] != -2) {
            if (memoR[r][c][dir] == -1) {
                return null;
            }
            return new int[]{memoR[r][c][dir], memoC[r][c][dir]};
        }

        int[] res;
        if (dir == 0) { // Entered moving Right -> turned Down -> next is (r + 1, c) entered Down (dir = 1)
            res = getLanding(grid, r + 1, c, 1, m, n, memoR, memoC);
        } else {        // Entered moving Down -> turned Right -> next is (r, c + 1) entered Right (dir = 0)
            res = getLanding(grid, r, c + 1, 0, m, n, memoR, memoC);
        }

        if (res == null) {
            memoR[r][c][dir] = -1;
            memoC[r][c][dir] = -1;
        } else {
            memoR[r][c][dir] = res[0];
            memoC[r][c][dir] = res[1];
        }

        return res;
    }
}