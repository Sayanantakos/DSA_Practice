class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[n + 1];
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int minPrev = dp[i - 1] + 1;

            if (i >= 2) {
                minPrev = Math.min(minPrev, dp[i - 2] + 4);
            }
            if (i >= 3) {
                minPrev = Math.min(minPrev, dp[i - 3] + 9);
            }

            dp[i] = minPrev + costs[i - 1];
        }

        return dp[n];
    }
}