#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int MIN_VAL = -10000;
        const int MAX_VAL = 10000;
        vector<int> count(MAX_VAL - MIN_VAL + 1, 0);

        // Step 1: Count element frequencies with offset mapping
        for (int num : nums) {
            count[num - MIN_VAL]++;
        }

        // Step 2: Traverse from largest to smallest to find the kth element
        int accumulated = 0;
        for (int i = count.size() - 1; i >= 0; --i) {
            accumulated += count[i];
            if (accumulated >= k) {
                return i + MIN_VAL;
            }
        }

        return -1;
    }
};