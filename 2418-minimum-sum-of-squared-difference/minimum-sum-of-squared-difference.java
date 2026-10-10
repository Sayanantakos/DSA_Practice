class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        int[] count = new int[100001];
        int maxDiff = 0;

        // Step 1: Calculate initial differences and count frequencies
        for (int i = 0; i < n; i++) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            count[diff]++;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }

        long k = (long) k1 + k2;

        // Step 2: Greedily reduce largest differences
        for (int d = maxDiff; d > 0 && k > 0; d--) {
            if (count[d] > 0) {
                long take = Math.min(k, (long) count[d]);
                count[d] -= take;
                count[d - 1] += take;
                k -= take;
            }
        }

        // Step 3: Compute sum of squared differences
        long result = 0;
        for (int d = 1; d <= maxDiff; d++) {
            if (count[d] > 0) {
                result += (long) count[d] * d * d;
            }
        }

        return result;
    }
}