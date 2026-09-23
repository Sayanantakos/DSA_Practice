#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Segment {
        int totalSum, maxPrefix, maxSuffix, maxSubarray;
    };

    Segment solve(const vector<int>& nums, int l, int r) {
        if (l == r) {
            return {nums[l], nums[l], nums[l], nums[l]};
        }

        int mid = l + (r - l) / 2;
        Segment left = solve(nums, l, mid);
        Segment right = solve(nums, mid + 1, r);

        int totalSum = left.totalSum + right.totalSum;
        int maxPrefix = max(left.maxPrefix, left.totalSum + right.maxPrefix);
        int maxSuffix = max(right.maxSuffix, right.totalSum + left.maxSuffix);
        int maxSubarray = max({left.maxSubarray, right.maxSubarray, left.maxSuffix + right.maxPrefix});

        return {totalSum, maxPrefix, maxSuffix, maxSubarray};
    }

public:
    int MaximumSubArray (vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1).maxSubarray;
    }
};