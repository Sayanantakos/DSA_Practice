#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        constexpr int MAX_LIMIT = 25200; // lcm(1..10) * 10 = 2520 * 10
        int n = nums.size();
        int maxLen = 2;

        for (int i = 0; i < n; ++i) {
            int prod = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                if (prod > MAX_LIMIT) {
                    break;
                }

                g = gcd(g, nums[j]);
                l = (l / gcd(l, nums[j])) * nums[j];

                if (prod == l * g) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};