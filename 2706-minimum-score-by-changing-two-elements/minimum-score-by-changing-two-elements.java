import java.util.Arrays;

class Solution {
    public int minimizeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        int dropTwoSmallest = nums[n - 1] - nums[2];
        int dropOneEach = nums[n - 2] - nums[1];
        int dropTwoLargest = nums[n - 3] - nums[0];

        return Math.min(dropTwoSmallest, Math.min(dropOneEach, dropTwoLargest));
    }
}