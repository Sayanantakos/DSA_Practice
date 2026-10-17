import java.util.Arrays;

class Solution {
    private static class Element {
        int val;
        int digitSum;
        int originalIndex;

        Element(int val, int digitSum, int originalIndex) {
            this.val = val;
            this.digitSum = digitSum;
            this.originalIndex = originalIndex;
        }
    }

    private int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;
        Element[] elements = new Element[n];

        // Step 1: Record digit sum and original indices
        for (int i = 0; i < n; i++) {
            elements[i] = new Element(nums[i], getDigitSum(nums[i]), i);
        }

        // Step 2: Sort by digitSum (primary) and val (secondary)
        Arrays.sort(elements, (a, b) -> {
            if (a.digitSum != b.digitSum) {
                return Integer.compare(a.digitSum, b.digitSum);
            }
            return Integer.compare(a.val, b.val);
        });

        // Step 3: Count minimum swaps via cycle decomposition
        boolean[] visited = new boolean[n];
        int totalSwaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || elements[i].originalIndex == i) {
                continue;
            }

            int cycleSize = 0;
            int curr = i;

            while (!visited[curr]) {
                visited[curr] = true;
                curr = elements[curr].originalIndex;
                cycleSize++;
            }

            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }

        return totalSwaps;
    }
}