#include <vector>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;
        for (int num = 100; num < 1000; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            freq[d1]--;
            freq[d2]--;
            freq[d3]--;

            if (freq[d1] >= 0 && freq[d2] >= 0 && freq[d3] >= 0) {
                count++;
            }

            freq[d1]++;
            freq[d2]++;
            freq[d3]++;
        }

        return count;
    }
};