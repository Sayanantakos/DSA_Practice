#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int dropTwoSmallest = nums[n - 1] - nums[2];
        int dropOneEach = nums[n - 2] - nums[1];
        int dropTwoLargest = nums[n - 3] - nums[0];

        return min({dropTwoSmallest, dropOneEach, dropTwoLargest});
    }
};