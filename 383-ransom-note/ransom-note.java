class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] charCounts = new int[26];

        // Count frequency of each character in magazine
        for (char c : magazine.toCharArray()) {
            charCounts[c - 'a']++;
        }

        // Check if ransomNote can be formed
        for (char c : ransomNote.toCharArray()) {
            if (--charCounts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
}