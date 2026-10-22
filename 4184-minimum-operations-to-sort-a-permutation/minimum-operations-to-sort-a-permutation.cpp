#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int costNormal(int n, int k) {
        if (k == 0) {
            return 0;
        }
        return min(n - k, k + 2);
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        bool isNormal = true;
        bool isReversed = true;

        for (int i = 0; i < n; ++i) {
            if (nums[i] != (nums[0] + i) % n) {
                isNormal = false;
            }
            if (nums[i] != (nums[0] - i + n) % n) {
                isReversed = false;
            }
        }

        // Case 1: Array is a Normal Shift
        if (isNormal) {
            int k = nums[0];
            return costNormal(n, k);
        }

        // Case 2: Array is a Reversed Shift
        if (isReversed) {
            int k = nums[0];

            // Option A: Reverse first, then solve as Normal Shift
            int kNorm = (k + 1) % n;
            int costA = 1 + costNormal(n, kNorm);

            // Option B: Rotate left to move element 0 to index n-1, then Reverse
            int costB = ((k + 1) % n) + 1;

            return min(costA, costB);
        }

        // Case 3: Impossible to sort
        return -1;
    }
};