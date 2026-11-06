import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int numLogs = logs.length;
        int numQueries = queries.length;

        // 1. Sort logs by timestamp (index 1)
        Arrays.sort(logs, Comparator.comparingInt(a -> a[1]));

        // 2. Store queries with their original indices: {q_time, original_index}
        int[][] sortedQueries = new int[numQueries][2];
        for (int i = 0; i < numQueries; i++) {
            sortedQueries[i][0] = queries[i];
            sortedQueries[i][1] = i;
        }
        Arrays.sort(sortedQueries, Comparator.comparingInt(a -> a[0]));

        int[] result = new int[numQueries];
        int[] freq = new int[n + 1];
        int activeServers = 0;
        int left = 0;
        int right = 0;

        // 3. Process queries using two-pointer sliding window
        for (int[] q : sortedQueries) {
            int qTime = q[0];
            int originalIdx = q[1];
            int winStart = qTime - x;
            int winEnd = qTime;

            // Expand right boundary: include logs with time <= winEnd
            while (right < numLogs && logs[right][1] <= winEnd) {
                int serverId = logs[right][0];
                if (freq[serverId] == 0) {
                    activeServers++;
                }
                freq[serverId]++;
                right++;
            }

            // Shrink left boundary: exclude logs with time < winStart
            while (left < numLogs && logs[left][1] < winStart) {
                int serverId = logs[left][0];
                freq[serverId]--;
                if (freq[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }

            result[originalIdx] = n - activeServers;
        }

        return result;
    }
}