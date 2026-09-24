class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int temp = nums[i];
            int digitSum = 0;
            
            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }
            
            if (digitSum == i) {
                return i;
            }
        }
        
        return -1;
    }
}