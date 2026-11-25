class Solution {
    public int smallestUniqueSubarray(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return 1;
        }

        // Step 1: Build Suffix Array in O(n log n) using Radix Sort
        int[] sa = new int[n];
        int[] rank = new int[n];
        int[] tmp = new int[n];

        int maxVal = n;
        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }

        int alphabet = maxVal + 1;
        int[] cnt = new int[alphabet + 1];

        for (int k = 1; k < n; k <<= 1) {
            // Counting sort by second key: rank[i + k] (0 represents out-of-bounds)
            for (int i = 0; i <= alphabet; i++) cnt[i] = 0;
            for (int i = 0; i < n; i++) {
                int key2 = (i + k < n) ? rank[i + k] : 0;
                cnt[key2]++;
            }
            for (int i = 1; i <= alphabet; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) {
                int key2 = (i + k < n) ? rank[i + k] : 0;
                tmp[--cnt[key2]] = i;
            }

            // Counting sort by first key: rank[i]
            for (int i = 0; i <= alphabet; i++) cnt[i] = 0;
            for (int i = 0; i < n; i++) cnt[rank[tmp[i]]]++;
            for (int i = 1; i <= alphabet; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) {
                int idx = tmp[i];
                sa[--cnt[rank[idx]]] = idx;
            }

            // Recompute equivalence classes (1-indexed so 0 remains reserved for out-of-bounds)
            tmp[sa[0]] = 1;
            int classes = 1;
            for (int i = 1; i < n; i++) {
                int prev = sa[i - 1];
                int curr = sa[i];
                int prev2 = (prev + k < n) ? rank[prev + k] : 0;
                int curr2 = (curr + k < n) ? rank[curr + k] : 0;
                if (rank[prev] != rank[curr] || prev2 != curr2) {
                    classes++;
                }
                tmp[curr] = classes;
            }

            System.arraycopy(tmp, 0, rank, 0, n);
            if (classes == n) {
                break;
            }
            alphabet = classes + 1;
        }

        // Step 2: Build LCP array in O(n) using Kasai's algorithm
        int[] invSa = new int[n];
        for (int i = 0; i < n; i++) {
            invSa[sa[i]] = i;
        }

        int[] lcp = new int[n];
        int h = 0;
        for (int i = 0; i < n; i++) {
            int idx = invSa[i];
            if (idx > 0) {
                int j = sa[idx - 1];
                while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                    h++;
                }
                lcp[idx] = h;
                if (h > 0) {
                    h--;
                }
            }
        }

        // Step 3: Find minimum valid unique prefix length across all suffixes
        int minLen = n;
        for (int idx = 0; idx < n; idx++) {
            int pos = sa[idx];
            int leftLcp = (idx > 0) ? lcp[idx] : 0;
            int rightLcp = (idx + 1 < n) ? lcp[idx + 1] : 0;
            int reqLen = Math.max(leftLcp, rightLcp) + 1;

            if (pos + reqLen <= n && reqLen < minLen) {
                minLen = reqLen;
            }
        }

        return minLen;
    }
}