#include <vector>

using namespace std;

class Solution {
    int m, n;
    int memo[100][100][101];

    bool dfs(vector<vector<char>>& grid, int r, int c, int open) {
        if (grid[r][c] == '(') {
            open++;
        } else {
            open--;
        }

        if (open < 0 || open > (m + n) / 2) return false;

        if (r == m - 1 && c == n - 1) {
            return open == 0;
        }

        if (memo[r][c][open] != -1) {
            return memo[r][c][open];
        }

        bool found = false;
        if (r + 1 < m) {
            found = found || dfs(grid, r + 1, c, open);
        }
        if (c + 1 < n) {
            found = found || dfs(grid, r, c + 1, open);
        }

        return memo[r][c][open] = found;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n) / 2; ++k) {
                    memo[i][j][k] = -1;
                }
            }
        }

        return dfs(grid, 0, 0, 0);
    }
};