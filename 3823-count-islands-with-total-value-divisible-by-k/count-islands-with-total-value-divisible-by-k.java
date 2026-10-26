class Solution {
    public int countIslands(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    // Accumulate total island value using a 64-bit integer
                    long islandSum = dfs(grid, visited, r, c, m, n);
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    private long dfs(int[][] grid, boolean[][] visited, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }

        visited[r][c] = true;
        long sum = grid[r][c];

        // 4-directional expansion
        sum += dfs(grid, visited, r + 1, c, m, n);
        sum += dfs(grid, visited, r - 1, c, m, n);
        sum += dfs(grid, visited, r, c + 1, m, n);
        sum += dfs(grid, visited, r, c - 1, m, n);

        return sum;
    }
}