#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 0) {
            return;
        }

        // Mark cell as visited by converting land to water
        grid[r][c] = 1;

        // Explore 4-directional neighbors
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Step 1: Flood fill land cells ('0') connected to the outer boundary
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    if (grid[r][c] == 0) {
                        dfs(grid, r, c, rows, cols);
                    }
                }
            }
        }

        // Step 2: Count remaining enclosed interior islands
        int closedIslandsCount = 0;
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(grid, r, c, rows, cols);
                }
            }
        }

        return closedIslandsCount;
    }
};