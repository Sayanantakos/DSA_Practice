#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessThanCount = 0;
        int targetCount = 0;

        // Step 1: Count elements smaller than and equal to target
        for (int num : nums) {
            if (num < target) {
                lessThanCount++;
            } else if (num == target) {
                targetCount++;
            }
        }

        // Step 2: Build the contiguous sequence of target indices
        vector<int> result;
        result.reserve(targetCount);
        for (int i = 0; i < targetCount; ++i) {
            result.push_back(lessThanCount + i);
        }

        return result;
    }
};