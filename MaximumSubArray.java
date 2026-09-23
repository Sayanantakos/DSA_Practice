class Solution {
    static class Segment {
        int totalSum, maxPrefix, maxSuffix, maxSubarray;

        Segment(int totalSum, int maxPrefix, int maxSuffix, int maxSubarray) {
            this.totalSum = totalSum;
            this.maxPrefix = maxPrefix;
            this.maxSuffix = maxSuffix;
            this.maxSubarray = maxSubarray;
        }
    }

    private Segment solve(int[] nums, int l, int r) {
        if (l == r) {
            return new Segment(nums[l], nums[l], nums[l], nums[l]);
        }

        int mid = l + (r - l) / 2;
        Segment left = solve(nums, l, mid);
        Segment right = solve(nums, mid + 1, r);

        int totalSum = left.totalSum + right.totalSum;
        int maxPrefix = Math.max(left.maxPrefix, left.totalSum + right.maxPrefix);
        int maxSuffix = Math.max(right.maxSuffix, right.totalSum + left.maxSuffix);
        int maxSubarray = Math.max(Math.max(left.maxSubarray, right.maxSubarray), left.maxSuffix + right.maxPrefix);

        return new Segment(totalSum, maxPrefix, maxSuffix, maxSubarray);
    }

    public int MaximumSubArray(int[] nums) {
        return solve(nums, 0, nums.length - 1).maxSubarray;
    }
}