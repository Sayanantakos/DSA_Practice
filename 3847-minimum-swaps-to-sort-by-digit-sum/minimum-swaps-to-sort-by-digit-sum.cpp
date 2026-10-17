#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct Element {
        int val;
        int digitSum;
        int originalIndex;
    };

    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<Element> elements(n);

        // Step 1: Record digit sum and original indices
        for (int i = 0; i < n; ++i) {
            elements[i] = {nums[i], getDigitSum(nums[i]), i};
        }

        // Step 2: Sort by digitSum (primary) and val (secondary)
        sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.val < b.val;
        });

        // Step 3: Count minimum swaps via cycle decomposition
        vector<bool> visited(n, false);
        int totalSwaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || elements[i].originalIndex == i) {
                continue;
            }

            int cycleSize = 0;
            int curr = i;

            while (!visited[curr]) {
                visited[curr] = true;
                curr = elements[curr].originalIndex;
                cycleSize++;
            }

            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }

        return totalSwaps;
    }
};