#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // Deque stores {value, count}, strictly increasing from front (left) to back (right)
        deque<pair<long long, long long>> dq;
        long long cost = 0;
        long long ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            long long x = nums[l];
            long long cnt = 1;

            // Merge front blocks whose prefix max is <= x
            while (!dq.empty() && dq.front().first <= x) {
                auto [val, c] = dq.front();
                dq.pop_front();
                cost += (x - val) * c;
                cnt += c;
            }
            dq.push_front({x, cnt});

            // Shrink window from the right while operations exceed k
            while (cost > k) {
                auto& back = dq.back();
                cost -= (back.first - nums[r]);
                back.second--;
                if (back.second == 0) {
                    dq.pop_back();
                }
                r--;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};