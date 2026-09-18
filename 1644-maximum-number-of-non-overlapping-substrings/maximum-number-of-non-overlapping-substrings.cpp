#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) {
                first[ch] = i;
            }
            last[ch] = i;
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) continue;

            int start = first[i];
            int end = last[i];
            bool valid = true;

            for (int j = start; j <= end; j++) {
                int ch = s[j] - 'a';
                if (first[ch] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[ch]);
            }

            if (valid) {
                intervals.push_back({start, end});
            }
        }

        // Sort intervals by end index
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<string> res;
        int prevEnd = -1;

        for (const auto& interval : intervals) {
            if (interval.first > prevEnd) {
                res.push_back(s.substr(interval.first, interval.second - interval.first + 1));
                prevEnd = interval.second;
            }
        }

        return res;
    }
};