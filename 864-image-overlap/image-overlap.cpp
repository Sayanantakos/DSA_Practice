#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> list1, list2;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c] == 1) list1.push_back({r, c});
                if (img2[r][c] == 1) list2.push_back({r, c});
            }
        }

        unordered_map<int, int> countMap;
        int maxOverlap = 0;

        for (const auto& p1 : list1) {
            for (const auto& p2 : list2) {
                int key = (p2.first - p1.first) * 100 + (p2.second - p1.second);
                countMap[key]++;
                maxOverlap = max(maxOverlap, countMap[key]);
            }
        }

        return maxOverlap;
    }
};