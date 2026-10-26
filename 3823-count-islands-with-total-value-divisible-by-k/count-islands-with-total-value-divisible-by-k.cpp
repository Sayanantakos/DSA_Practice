#include <vector>

using namespace std;

class Solution {
private:
    long long dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }

        visited[r][c] = true;
        long long sum = grid[r][c];

        // 4-directional expansion
        sum += dfs(grid, visited, r + 1, c, m, n);
        sum += dfs(grid, visited, r - 1, c, m, n);
        sum += dfs(grid, visited, r, c + 1, m, n);
        sum += dfs(grid, visited, r, c - 1, m, n);

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    // Accumulate total island value using a 64-bit integer
                    long long islandSum = dfs(grid, visited, r, c, m, n);
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};