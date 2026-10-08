class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder result = new StringBuilder();
        int open = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') {
                if (open > 0) {
                    result.append(c);
                }
                open++;
            } else {
                open--;
                if (open > 0) {
                    result.append(c);
                }
            }
        }

        return result.toString();
    }
}