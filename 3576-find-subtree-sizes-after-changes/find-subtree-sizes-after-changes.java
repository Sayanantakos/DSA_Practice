import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private List<Integer>[] adj;
    private int[] newParent;
    private int[] lastSeen;
    private int[] ans;
    private String s;

    @SuppressWarnings("unchecked")
    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;
        this.s = s;
        this.newParent = Arrays.copyOf(parent, n);
        this.lastSeen = new int[26];
        Arrays.fill(this.lastSeen, -1);

        // Build adjacency list for the original tree
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            adj[parent[i]].add(i);
        }

        // Pass 1: Determine simultaneous new parents
        dfsFindParents(0);

        // Rebuild adjacency list for the final tree
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            adj[newParent[i]].add(i);
        }

        // Pass 2: Compute subtree sizes in the final tree
        ans = new int[n];
        Arrays.fill(ans, 1);
        dfsComputeSizes(0);

        return ans;
    }

    private void dfsFindParents(int u) {
        int c = s.charAt(u) - 'a';
        if (lastSeen[c] != -1) {
            newParent[u] = lastSeen[c];
        }

        int prev = lastSeen[c];
        lastSeen[c] = u;

        for (int v : adj[u]) {
            dfsFindParents(v);
        }

        lastSeen[c] = prev;
    }

    private void dfsComputeSizes(int u) {
        for (int v : adj[u]) {
            dfsComputeSizes(v);
            ans[u] += ans[v];
        }
    }
}