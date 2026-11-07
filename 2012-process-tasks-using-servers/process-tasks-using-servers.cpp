#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // freeServers: pair<weight, index> (Min-Heap)
        using FreeServer = pair<int, int>;
        priority_queue<FreeServer, vector<FreeServer>, greater<FreeServer>> freeServers;

        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }

        // busyServers: tuple<availableTime, weight, index> (Min-Heap)
        using BusyServer = tuple<long long, int, int>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busyServers;

        vector<int> ans(m);
        long long currTime = 0;

        for (int j = 0; j < m; ++j) {
            currTime = max(currTime, static_cast<long long>(j));

            // Release servers that completed their work by currTime
            while (!busyServers.empty() && get<0>(busyServers.top()) <= currTime) {
                auto [availTime, w, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({w, idx});
            }

            // If no free servers, fast-forward time to the next available server
            if (freeServers.empty()) {
                currTime = get<0>(busyServers.top());
                while (!busyServers.empty() && get<0>(busyServers.top()) <= currTime) {
                    auto [availTime, w, idx] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({w, idx});
                }
            }

            // Assign task j to the best available free server
            auto [w, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;
            busyServers.push({currTime + tasks[j], w, idx});
        }

        return ans;
    }
};