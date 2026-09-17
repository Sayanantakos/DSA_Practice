#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> best(n, INF);

        int ans = INF;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }
                best[right] = min(right > 0 ? best[right - 1] : INF, len);
            } else {
                best[right] = right > 0 ? best[right - 1] : INF;
            }
        }

        return ans >= INF ? -1 : ans;
    }
};