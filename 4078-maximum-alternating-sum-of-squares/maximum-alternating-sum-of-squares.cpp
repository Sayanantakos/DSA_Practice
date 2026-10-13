#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);

        for (int i = 0; i < n; ++i) {
            squares[i] = (long long)nums[i] * nums[i];
        }

        sort(squares.begin(), squares.end());

        long long score = 0;
        int numSubtractions = n / 2;

        // Subtract the smallest n / 2 squares
        for (int i = 0; i < numSubtractions; ++i) {
            score -= squares[i];
        }

        // Add the remaining largest squares
        for (int i = numSubtractions; i < n; ++i) {
            score += squares[i];
        }

        return score;
    }
};