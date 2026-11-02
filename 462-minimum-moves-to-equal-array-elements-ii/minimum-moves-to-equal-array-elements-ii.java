import java.util.Arrays;

class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        
        int left = 0;
        int right = nums.length - 1;
        long moves = 0;
        
        while (left < right) {
            moves += (nums[right] - nums[left]);
            left++;
            right--;
        }
        
        return (int) moves;
    }
}