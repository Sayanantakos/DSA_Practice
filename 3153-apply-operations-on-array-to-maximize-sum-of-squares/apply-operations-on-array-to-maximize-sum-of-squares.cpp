#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(31, 0);
        long long MOD = 1e9 + 7;

        // Step 1: Count set bits at each position across all numbers
        for (int num : nums) {
            for (int b = 0; b < 31; ++b) {
                if ((num >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        long long totalSum = 0;

        // Step 2: Greedily construct the k largest possible numbers
        for (int i = 0; i < k; ++i) {
            long long currentVal = 0;
            for (int b = 0; b < 31; ++b) {
                if (bitCount[b] > 0) {
                    currentVal |= (1LL << b);
                    bitCount[b]--;
                }
            }
            long long valMod = currentVal % MOD;
            totalSum = (totalSum + valMod * valMod) % MOD;
        }

        return totalSum;
    }
};