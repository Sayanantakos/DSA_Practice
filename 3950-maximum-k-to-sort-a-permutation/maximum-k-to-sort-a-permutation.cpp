#include <vector>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxK = -1;

        // Compute bitwise AND of all misplaced elements
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                if (maxK == -1) {
                    maxK = nums[i];
                } else {
                    maxK &= nums[i];
                }
            }
        }

        // If no elements were misplaced, the array is already sorted
        return maxK == -1 ? 0 : maxK;
    }
};