import java.util.*;

class Solution {
    private int ptr = 0;

    public List<String> braceExpansionII(String expression) {
        ptr = 0;
        Set<String> set = parseExpr(expression);
        List<String> result = new ArrayList<>(set);
        Collections.sort(result); // Return sorted unique words
        return result;
    }

    private Set<String> parseExpr(String s) {
        Set<String> res = new HashSet<>();
        List<Set<String>> currentTermFactors = new ArrayList<>();

        while (ptr < s.length() && s.charAt(ptr) != '}') {
            if (s.charAt(ptr) == ',') {
                res.addAll(multiplyFactors(currentTermFactors));
                currentTermFactors.clear();
                ptr++; // Skip ','
            } else {
                currentTermFactors.add(parseFactor(s));
            }
        }

        res.addAll(multiplyFactors(currentTermFactors));
        return res;
    }

    private Set<String> parseFactor(String s) {
        if (s.charAt(ptr) == '{') {
            ptr++; // Skip '{'
            Set<String> res = parseExpr(s);
            ptr++; // Skip '}'
            return res;
        } else {
            Set<String> res = new HashSet<>();
            res.add(String.valueOf(s.charAt(ptr)));
            ptr++; // Skip single character
            return res;
        }
    }

    private Set<String> multiplyFactors(List<Set<String>> factors) {
        if (factors.isEmpty()) return Collections.emptySet();

        Set<String> result = new HashSet<>();
        result.add("");

        for (Set<String> factor : factors) {
            Set<String> nextResult = new HashSet<>();
            for (String s1 : result) {
                for (String s2 : factor) {
                    nextResult.add(s1 + s2);
                }
            }
            result = nextResult;
        }

        return result;
    }
}