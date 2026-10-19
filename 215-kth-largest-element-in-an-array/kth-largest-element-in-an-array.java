class Solution {
    public int findKthLargest(int[] nums, int k) {
        int minVal = -10000;
        int maxVal = 10000;
        int[] count = new int[maxVal - minVal + 1];

        // Step 1: Count element frequencies with offset mapping
        for (int num : nums) {
            count[num - minVal]++;
        }

        // Step 2: Traverse from largest to smallest to find the kth element
        int accumulated = 0;
        for (int i = count.length - 1; i >= 0; i--) {
            accumulated += count[i];
            if (accumulated >= k) {
                return i + minVal;
            }
        }

        return -1;
    }
}