class Solution {
    public String[] createGrid(int m, int n) {
        String[] grid = new String[m];

        // First row: all free cells '.'
        grid[0] = ".".repeat(n);

        // Remaining rows: (n - 1) obstacle cells '#' followed by 1 free cell '.'
        String rowPattern = "#".repeat(n - 1) + ".";
        for (int r = 1; r < m; r++) {
            grid[r] = rowPattern;
        }

        return grid;
    }
}