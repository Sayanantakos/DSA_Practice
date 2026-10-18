#include <vector>

using namespace std;

class Solution {
private:
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long dfs(const vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) {
            return 1;
        }

        int root = nums[0];
        vector<int> left;
        vector<int> right;

        for (int i = 1; i < m; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(left);
        long long rightWays = dfs(right);

        long long combinations = comb[m - 1][left.size()];
        return (combinations * leftWays % MOD) * rightWays % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        comb.assign(n + 1, vector<long long>(n + 1, 0));

        // Precompute Pascal's triangle for combinations C(n, k)
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};