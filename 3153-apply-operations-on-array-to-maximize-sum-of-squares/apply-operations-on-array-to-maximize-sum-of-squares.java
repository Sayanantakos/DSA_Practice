import java.util.List;

class Solution {
    public int maxSum(List<Integer> nums, int k) {
        int[] bitCount = new int[31];
        long MOD = 1_000_000_007;

        // Step 1: Count set bits at each position across all numbers
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if (((num >> b) & 1) == 1) {
                    bitCount[b]++;
                }
            }
        }

        long totalSum = 0;

        // Step 2: Greedily construct the k largest possible numbers
        for (int i = 0; i < k; i++) {
            long currentVal = 0;
            for (int b = 0; b < 31; b++) {
                if (bitCount[b] > 0) {
                    currentVal |= (1L << b);
                    bitCount[b]--;
                }
            }
            long valMod = currentVal % MOD;
            totalSum = (totalSum + valMod * valMod) % MOD;
        }

        return (int) totalSum;
    }
}