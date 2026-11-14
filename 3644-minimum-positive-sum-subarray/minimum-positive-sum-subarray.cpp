#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int currSum = 0;
            int maxEnd = min(n, i + r);

            for (int j = i; j < maxEnd; ++j) {
                currSum += nums[j];
                int len = j - i + 1;

                if (len >= l && currSum > 0) {
                    minSum = min(minSum, currSum);
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};