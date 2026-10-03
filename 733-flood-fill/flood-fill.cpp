#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int color) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != originalColor) {
            return;
        }

        image[r][c] = color;

        // Explore 4-directional adjacent neighbors
        dfs(image, r + 1, c, originalColor, color);
        dfs(image, r - 1, c, originalColor, color);
        dfs(image, r, c + 1, originalColor, color);
        dfs(image, r, c - 1, originalColor, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, originalColor, color);
        }
        return image;
    }
};