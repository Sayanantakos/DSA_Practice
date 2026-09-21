#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);
            int numMod = num % k;

            // Start a new subarray consisting of only current element
            newDp[numMod]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newMod = (r * numMod) % k;
                    newDp[newMod] += dp[r];
                }
            }

            // Accumulate counts into result
            for (int r = 0; r < k; r++) {
                result[r] += newDp[r];
            }

            dp = std::move(newDp);
        }

        return result;
    }
};