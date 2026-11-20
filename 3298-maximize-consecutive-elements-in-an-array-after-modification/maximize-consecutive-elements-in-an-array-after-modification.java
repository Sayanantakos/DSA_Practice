import java.util.Arrays;

class Solution {
    public int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int maxVal = nums[nums.length - 1];
        int[] dp = new int[maxVal + 2];
        int maxLen = 1;

        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;

            if (dp[x + 1] > maxLen) {
                maxLen = dp[x + 1];
            }
            if (dp[x] > maxLen) {
                maxLen = dp[x];
            }
        }

        return maxLen;
    }
}