import java.util.List;

class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();
        int minSum = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int currSum = 0;
            int maxEnd = Math.min(n, i + r);

            for (int j = i; j < maxEnd; j++) {
                currSum += nums.get(j);
                int len = j - i + 1;

                if (len >= l && currSum > 0) {
                    minSum = Math.min(minSum, currSum);
                }
            }
        }

        return minSum == Integer.MAX_VALUE ? -1 : minSum;
    }
}