#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    int ptr = 0;

    unordered_set<string> multiplyFactors(const vector<unordered_set<string>>& factors) {
        if (factors.empty()) return {};

        unordered_set<string> result = {""};
        for (const auto& factor : factors) {
            unordered_set<string> nextResult;
            for (const string& s1 : result) {
                for (const string& s2 : factor) {
                    nextResult.insert(s1 + s2);
                }
            }
            result = move(nextResult);
        }
        return result;
    }

    unordered_set<string> parseExpr(const string& s) {
        unordered_set<string> res;
        vector<unordered_set<string>> currentTermFactors;

        while (ptr < s.length() && s[ptr] != '}') {
            if (s[ptr] == ',') {
                auto combined = multiplyFactors(currentTermFactors);
                res.insert(combined.begin(), combined.end());
                currentTermFactors.clear();
                ptr++; // Skip ','
            } else {
                currentTermFactors.push_back(parseFactor(s));
            }
        }

        auto combined = multiplyFactors(currentTermFactors);
        res.insert(combined.begin(), combined.end());
        return res;
    }

    unordered_set<string> parseFactor(const string& s) {
        if (s[ptr] == '{') {
            ptr++; // Skip '{'
            auto res = parseExpr(s);
            ptr++; // Skip '}'
            return res;
        } else {
            unordered_set<string> res = {string(1, s[ptr])};
            ptr++; // Skip single character
            return res;
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        ptr = 0;
        auto setRes = parseExpr(expression);
        vector<string> result(setRes.begin(), setRes.end());
        sort(result.begin(), result.end()); // Return sorted unique words
        return result;
    }
};