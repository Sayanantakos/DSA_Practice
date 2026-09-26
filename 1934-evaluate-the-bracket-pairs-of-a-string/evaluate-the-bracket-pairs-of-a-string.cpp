#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Build unordered_map for O(1) key lookups
        unordered_map<string, string> map;
        for (const auto& pair : knowledge) {
            map[pair[0]] = pair[1];
        }

        string result = "";
        string key = "";
        bool inBracket = false;

        for (char c : s) {
            if (c == '(') {
                inBracket = true;
            } else if (c == ')') {
                inBracket = false;
                auto it = map.find(key);
                if (it != map.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                key.clear(); // Reset key buffer
            } else {
                if (inBracket) {
                    key += c;
                } else {
                    result += c;
                }
            }
        }

        return result;
    }
};