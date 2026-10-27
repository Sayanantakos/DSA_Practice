#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);

        // First row: all free cells '.'
        grid[0] = string(n, '.');

        // Remaining rows: (n - 1) obstacle cells '#' followed by 1 free cell '.'
        string rowPattern = string(n - 1, '#') + ".";
        for (int r = 1; r < m; ++r) {
            grid[r] = rowPattern;
        }

        return grid;
    }
};