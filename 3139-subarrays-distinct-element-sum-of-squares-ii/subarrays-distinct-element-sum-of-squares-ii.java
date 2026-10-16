import java.util.Arrays;

class Solution {
    private static final int MOD = 1_000_000_007;

    private long[] sumD;
    private long[] sumSq;
    private long[] lazy;

    private void apply(int node, long len, long val) {
        val %= MOD;
        long valSqLen = (val * val % MOD) * len % MOD;
        long twoValSumD = (2 * val % MOD) * sumD[node] % MOD;

        sumSq[node] = (sumSq[node] + twoValSumD + valSqLen) % MOD;
        sumD[node] = (sumD[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    private void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, mid - l + 1, lazy[node]);
            apply(2 * node + 1, r - mid, lazy[node]);
            lazy[node] = 0;
        }
    }

    private void update(int node, int l, int r, int ql, int qr, long val) {
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, val);
            return;
        }

        push(node, l, r);
        int mid = l + (r - l) / 2;

        if (ql <= mid) {
            update(2 * node, l, mid, ql, qr, val);
        }
        if (qr > mid) {
            update(2 * node + 1, mid + 1, r, ql, qr, val);
        }

        sumD[node] = (sumD[2 * node] + sumD[2 * node + 1]) % MOD;
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
    }

    public int sumCounts(int[] nums) {
        int n = nums.length;
        int maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }

        sumD = new long[4 * n];
        sumSq = new long[4 * n];
        lazy = new long[4 * n];

        int[] lastPos = new int[maxVal + 1];
        Arrays.fill(lastPos, -1);

        long totalSum = 0;

        for (int j = 0; j < n; j++) {
            int val = nums[j];
            int prev = lastPos[val];

            update(1, 0, n - 1, prev + 1, j, 1);
            lastPos[val] = j;

            totalSum = (totalSum + sumSq[1]) % MOD;
        }

        return (int) totalSum;
    }
}