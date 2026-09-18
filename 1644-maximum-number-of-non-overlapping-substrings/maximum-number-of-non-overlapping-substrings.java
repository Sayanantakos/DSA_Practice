import java.util.*;

class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        Arrays.fill(last, -1);

        for (int i = 0; i < n; i++) {
            int ch = s.charAt(i) - 'a';
            if (first[ch] == -1) {
                first[ch] = i;
            }
            last[ch] = i;
        }

        List<int[]> intervals = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) continue;

            int start = first[i];
            int end = last[i];
            boolean valid = true;

            for (int j = start; j <= end; j++) {
                int ch = s.charAt(j) - 'a';
                if (first[ch] < start) {
                    valid = false;
                    break;
                }
                end = Math.max(end, last[ch]);
            }

            if (valid) {
                intervals.add(new int[]{start, end});
            }
        }

        // Sort intervals by end index
        intervals.sort((a, b) -> Integer.compare(a[1], b[1]));

        List<String> res = new ArrayList<>();
        int prevEnd = -1;

        for (int[] interval : intervals) {
            if (interval[0] > prevEnd) {
                res.add(s.substring(interval[0], interval[1] + 1));
                prevEnd = interval[1];
            }
        }

        return res;
    }
}