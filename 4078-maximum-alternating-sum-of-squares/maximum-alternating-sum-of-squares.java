import java.util.Arrays;

class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;
        long[] squares = new long[n];

        for (int i = 0; i < n; i++) {
            squares[i] = (long) nums[i] * nums[i];
        }

        Arrays.sort(squares);

        long score = 0;
        int numSubtractions = n / 2;

        // Subtract the smallest n / 2 squares
        for (int i = 0; i < numSubtractions; i++) {
            score -= squares[i];
        }

        // Add the remaining largest squares
        for (int i = numSubtractions; i < n; i++) {
            score += squares[i];
        }

        return score;
    }
}