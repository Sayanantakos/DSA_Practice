#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        // Pass 1: Count total servers in each row and column
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }

        // Pass 2: Count servers that can communicate
        int communicatingServers = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    if (rowCount[r] > 1 || colCount[c] > 1) {
                        communicatingServers++;
                    }
                }
            }
        }

        return communicatingServers;
    }
};