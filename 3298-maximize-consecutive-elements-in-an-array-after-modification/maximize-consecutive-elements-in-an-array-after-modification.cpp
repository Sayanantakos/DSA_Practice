#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxVal = nums.back();
        vector<int> dp(maxVal + 2, 0);
        int maxLen = 1;

        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            maxLen = max({maxLen, dp[x + 1], dp[x]});
        }

        return maxLen;
    }
};