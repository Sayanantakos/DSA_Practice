#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static const int MOD = 1e9 + 7;
    vector<long long> sumD;
    vector<long long> sumSq;
    vector<long long> lazy;

    void apply(int node, long long len, long long val) {
        val %= MOD;
        long long valSqLen = (val * val % MOD) * len % MOD;
        long long twoValSumD = (2 * val % MOD) * sumD[node] % MOD;

        sumSq[node] = (sumSq[node] + twoValSumD + valSqLen) % MOD;
        sumD[node] = (sumD[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, mid - l + 1, lazy[node]);
            apply(2 * node + 1, r - mid, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
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

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }

        sumD.assign(4 * n, 0);
        sumSq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> lastPos(maxVal + 1, -1);
        long long totalSum = 0;

        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            int prev = lastPos[val];

            update(1, 0, n - 1, prev + 1, j, 1);
            lastPos[val] = j;

            totalSum = (totalSum + sumSq[1]) % MOD;
        }

        return totalSum;
    }
};