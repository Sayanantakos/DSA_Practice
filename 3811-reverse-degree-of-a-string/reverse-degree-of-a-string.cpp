#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        for (int i = 0; i < s.length(); i++) {
            int reversedAlphaPos = 'z' - s[i] + 1;
            int stringPos = i + 1;
            totalSum += reversedAlphaPos * stringPos;
        }
        return totalSum;
    }
};