import java.util.*;

class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        // Build HashMap for O(1) key lookups
        Map<String, String> map = new HashMap<>();
        for (List<String> pair : knowledge) {
            map.put(pair.get(0), pair.get(1));
        }

        StringBuilder result = new StringBuilder();
        StringBuilder key = new StringBuilder();
        boolean inBracket = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(') {
                inBracket = true;
            } else if (c == ')') {
                inBracket = false;
                result.append(map.getOrDefault(key.toString(), "?"));
                key.setLength(0); // Reset key buffer
            } else {
                if (inBracket) {
                    key.append(c);
                } else {
                    result.append(c);
                }
            }
        }

        return result.toString();
    }
}