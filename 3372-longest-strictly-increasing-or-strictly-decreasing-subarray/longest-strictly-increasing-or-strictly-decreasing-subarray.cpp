#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incLen = 1;
        int decLen = 1;
        int maxLen = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1;
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }

            maxLen = max({maxLen, incLen, decLen});
        }

        return maxLen;
    }
};