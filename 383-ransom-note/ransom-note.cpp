#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charCounts(26, 0);

        // Count frequency of each character in magazine
        for (char c : magazine) {
            charCounts[c - 'a']++;
        }

        // Check if ransomNote can be formed
        for (char c : ransomNote) {
            if (--charCounts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};