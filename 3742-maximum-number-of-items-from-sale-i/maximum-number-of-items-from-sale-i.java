class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        int[] bonus = new int[n];

        // Step 1: Precompute free copies unlocked by purchasing >= 1 copy of item i
        for (int i = 0; i < n; i++) {
            int factorI = items[i][0];
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factorI == 0) {
                    bonus[i]++;
                }
            }
        }

        // Step 2: Two-stage knapsack DP (0-1 first copy + unbounded extra copies)
        int[] dp = new int[budget + 1];

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            if (price > budget) {
                continue;
            }

            int firstCopyVal = 1 + bonus[i];
            for (int b = budget; b >= price; b--) {
                dp[b] = Math.max(dp[b], dp[b - price] + firstCopyVal);
            }

            for (int b = price; b <= budget; b++) {
                dp[b] = Math.max(dp[b], dp[b - price] + 1);
            }
        }

        return dp[budget];
    }
}