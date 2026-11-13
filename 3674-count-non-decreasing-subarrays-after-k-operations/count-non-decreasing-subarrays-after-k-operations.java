import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length;
        // Deque stores {value, count}, strictly increasing from front (left) to back (right)
        Deque<long[]> dq = new ArrayDeque<>();
        long cost = 0;
        long ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            long x = nums[l];
            long cnt = 1;

            // Merge front blocks whose prefix max is <= x
            while (!dq.isEmpty() && dq.peekFirst()[0] <= x) {
                long[] front = dq.pollFirst();
                cost += (x - front[0]) * front[1];
                cnt += front[1];
            }
            dq.offerFirst(new long[]{x, cnt});

            // Shrink window from the right while operations exceed k
            while (cost > k) {
                long[] back = dq.peekLast();
                cost -= (back[0] - nums[r]);
                back[1]--;
                if (back[1] == 0) {
                    dq.pollLast();
                }
                r--;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
}