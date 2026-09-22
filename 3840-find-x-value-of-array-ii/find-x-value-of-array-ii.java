class Solution {
    static class Node {
        int prod;
        int[] count;

        Node() {
            this.prod = 1;
            this.count = new int[5];
        }
    }

    private Node[] tree;
    private int n;
    private int k;

    private Node makeNode(long val) {
        Node res = new Node();
        res.prod = (int)(val % k);
        res.count[res.prod] = 1;
        return res;
    }

    private Node merge(Node left, Node right) {
        Node res = new Node();
        res.prod = (left.prod * right.prod) % k;
        
        for (int r = 0; r < k; r++) {
            res.count[r] = left.count[r];
        }
        for (int r = 0; r < k; r++) {
            int newR = (left.prod * r) % k;
            res.count[newR] += right.count[r];
        }
        return res;
    }

    private void build(int node, int l, int r, int[] nums) {
        if (l == r) {
            tree[node] = makeNode(nums[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    private void update(int node, int l, int r, int idx, long val) {
        if (l == r) {
            tree[node] = makeNode(val);
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node + 1, l, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, r, idx, val);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    private Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return query(2 * node + 1, l, mid, ql, qr);
        }
        if (ql > mid) {
            return query(2 * node + 2, mid + 1, r, ql, qr);
        }
        Node leftResult = query(2 * node + 1, l, mid, ql, qr);
        Node rightResult = query(2 * node + 2, mid + 1, r, ql, qr);
        return merge(leftResult, rightResult);
    }

    public int[] resultArray(int[] nums, int k, int[][] queries) {
        this.n = nums.length;
        this.k = k;
        this.tree = new Node[4 * n];

        build(0, 0, n - 1, nums);

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int idx = queries[i][0];
            int val = queries[i][1];
            int start = queries[i][2];
            int x = queries[i][3];

            update(0, 0, n - 1, idx, val);
            Node resNode = query(0, 0, n - 1, start, n - 1);
            result[i] = resNode.count[x];
        }

        return result;
    }
}