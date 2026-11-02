#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.size() - 1;
        long long moves = 0;
        
        while (left < right) {
            moves += (nums[right] - nums[left]);
            left++;
            right--;
        }
        
        return static_cast<int>(moves);
    }
};