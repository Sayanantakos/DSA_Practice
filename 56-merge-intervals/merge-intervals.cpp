#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on starting value
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= merged.back()[1]) {
                // Overlapping intervals, update end time
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // Non-overlapping interval, push to merged
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};