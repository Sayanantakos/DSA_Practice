#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        array<int, 26> lastSeen;
        lastSeen.fill(-1);

        // Pass 1: Determine simultaneous new parents
        auto dfsFindParents = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            if (lastSeen[c] != -1) {
                newParent[u] = lastSeen[c];
            }

            int prev = lastSeen[c];
            lastSeen[c] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            lastSeen[c] = prev;
        };

        dfsFindParents(dfsFindParents, 0);

        // Rebuild adjacency list for the final tree
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            adj[newParent[i]].push_back(i);
        }

        // Pass 2: Compute subtree sizes in the final tree
        vector<int> ans(n, 1);
        auto dfsComputeSizes = [&](auto& self, int u) -> void {
            for (int v : adj[u]) {
                self(self, v);
                ans[u] += ans[v];
            }
        };

        dfsComputeSizes(dfsComputeSizes, 0);

        return ans;
    }
};