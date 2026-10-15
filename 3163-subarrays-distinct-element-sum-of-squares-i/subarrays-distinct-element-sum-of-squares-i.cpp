#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinct;
            for (int j = i; j < n; ++j) {
                distinct.insert(nums[j]);
                int count = distinct.size();
                totalSum += count * count;
            }
        }

        return totalSum;
    }
};