#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int evenCount = 1; // Empty prefix sum (0) is even
        int oddCount = 0;
        int prefixParity = 0;
        int ans = 0;

        for (int num : arr) {
            prefixParity ^= (num & 1);

            if (prefixParity == 1) {
                ans = (ans + evenCount) % MOD;
                oddCount++;
            } else {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }

        return ans;
    }
};