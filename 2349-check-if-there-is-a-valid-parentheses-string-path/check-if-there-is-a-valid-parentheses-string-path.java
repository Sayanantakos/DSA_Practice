class Solution {
    private Boolean[][][] memo;
    private int m, n;

    public boolean hasValidPath(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // Path length is m + n - 1; valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0) return false;
        // Path must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memo = new Boolean[m][n][(m + n) / 2 + 1];
        return dfs(grid, 0, 0, 0);
    }

    private boolean dfs(char[][] grid, int r, int c, int open) {
        if (grid[r][c] == '(') {
            open++;
        } else {
            open--;
        }

        // Invalid if closing brackets exceed opening brackets or open count exceeds max limit
        if (open < 0 || open > (m + n) / 2) return false;

        // Reached destination cell
        if (r == m - 1 && c == n - 1) {
            return open == 0;
        }

        if (memo[r][c][open] != null) {
            return memo[r][c][open];
        }

        boolean found = false;
        if (r + 1 < m) {
            found = found || dfs(grid, r + 1, c, open);
        }
        if (c + 1 < n) {
            found = found || dfs(grid, r, c + 1, open);
        }

        return memo[r][c][open] = found;
    }
}