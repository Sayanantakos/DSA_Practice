import java.util.*;

class Solution {
    private Set<String> validStrings = new HashSet<>();

    public List<String> removeInvalidParentheses(String s) {
        int remL = 0;
        int remR = 0;

        // Step 1: Calculate minimum left and right parentheses to remove
        for (char c : s.toCharArray()) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) {
                    remL--;
                } else {
                    remR++;
                }
            }
        }

        // Step 2: Backtrack to find all valid combinations
        backtrack(s, 0, 0, remL, remR, new StringBuilder());
        return new ArrayList<>(validStrings);
    }

    private void backtrack(String s, int index, int openCount, int remL, int remR, StringBuilder current) {
        if (index == s.length()) {
            if (remL == 0 && remR == 0 && openCount == 0) {
                validStrings.add(current.toString());
            }
            return;
        }

        char c = s.charAt(index);
        int len = current.length();

        // Option 1: Remove current character
        if (c == '(' && remL > 0) {
            backtrack(s, index + 1, openCount, remL - 1, remR, current);
        } else if (c == ')' && remR > 0) {
            backtrack(s, index + 1, openCount, remL, remR - 1, current);
        }

        // Option 2: Keep current character
        if (c != '(' && c != ')') {
            current.append(c);
            backtrack(s, index + 1, openCount, remL, remR, current);
            current.setLength(len);
        } else if (c == '(') {
            current.append(c);
            backtrack(s, index + 1, openCount + 1, remL, remR, current);
            current.setLength(len);
        } else if (c == ')' && openCount > 0) {
            current.append(c);
            backtrack(s, index + 1, openCount - 1, remL, remR, current);
            current.setLength(len);
        }
    }
}