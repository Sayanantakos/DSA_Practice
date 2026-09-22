#include <vector>

using namespace std;

class Solution {
    struct Node {
        int prod = 1;
        int count[5] = {0};
    };

    int n;
    int k;
    vector<Node> tree;

    Node makeNode(long long val) {
        Node res;
        res.prod = val % k;
        res.count[res.prod] = 1;
        return res;
    }

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        for (int r = 0; r < k; ++r) {
            res.count[r] = left.count[r];
        }
        for (int r = 0; r < k; ++r) {
            int newR = (left.prod * r) % k;
            res.count[newR] += right.count[r];
        }
        return res;
    }

    void build(int node, int l, int r, const vector<int>& nums) {
        if (l == r) {
            tree[node] = makeNode(nums[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int l, int r, int idx, long long val) {
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

    Node query(int node, int l, int r, int ql, int qr) {
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

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;
        this->tree.resize(4 * n);

        build(0, 0, n - 1, nums);

        vector<int> result(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
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
};