import java.util.PriorityQueue;

class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;

        // freeServers: sorted by [weight, index]
        PriorityQueue<int[]> freeServers = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        for (int i = 0; i < n; i++) {
            freeServers.offer(new int[]{servers[i], i});
        }

        // busyServers: sorted by [availableTime (long), weight, index]
        PriorityQueue<long[]> busyServers = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Long.compare(a[0], b[0]);
            if (a[1] != b[1]) return Long.compare(a[1], b[1]);
            return Long.compare(a[2], b[2]);
        });

        int[] ans = new int[m];
        long currTime = 0;

        for (int j = 0; j < m; j++) {
            currTime = Math.max(currTime, (long) j);

            // Release servers that completed their work by currTime
            while (!busyServers.isEmpty() && busyServers.peek()[0] <= currTime) {
                long[] freed = busyServers.poll();
                freeServers.offer(new int[]{(int) freed[1], (int) freed[2]});
            }

            // If no free servers, fast-forward time to the next available server
            if (freeServers.isEmpty()) {
                currTime = busyServers.peek()[0];
                while (!busyServers.isEmpty() && busyServers.peek()[0] <= currTime) {
                    long[] freed = busyServers.poll();
                    freeServers.offer(new int[]{(int) freed[1], (int) freed[2]});
                }
            }

            // Assign task j to the best available free server
            int[] server = freeServers.poll();
            int weight = server[0];
            int index = server[1];

            ans[j] = index;
            busyServers.offer(new long[]{currTime + tasks[j], weight, index});
        }

        return ans;
    }
}