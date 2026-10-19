import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int lessThanCount = 0;
        int targetCount = 0;

        // Step 1: Count elements smaller than and equal to target
        for (int num : nums) {
            if (num < target) {
                lessThanCount++;
            } else if (num == target) {
                targetCount++;
            }
        }

        // Step 2: Build the contiguous sequence of target indices
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < targetCount; i++) {
            result.add(lessThanCount + i);
        }

        return result;
    }
}