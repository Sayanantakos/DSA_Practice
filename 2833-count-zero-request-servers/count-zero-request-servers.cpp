#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int numLogs = logs.size();
        int numQueries = queries.size();

        // 1. Sort logs by timestamp (logs[i][1])
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // 2. Store queries with their original indices: {q_time, original_index}
        vector<pair<int, int>> sortedQueries(numQueries);
        for (int i = 0; i < numQueries; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(numQueries);
        vector<int> freq(n + 1, 0);
        int activeServers = 0;
        int left = 0;
        int right = 0;

        // 3. Process queries using two-pointer sliding window
        for (const auto& [qTime, originalIdx] : sortedQueries) {
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
};