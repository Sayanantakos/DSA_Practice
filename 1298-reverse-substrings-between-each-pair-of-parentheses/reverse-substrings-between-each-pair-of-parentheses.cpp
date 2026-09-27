#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;

        // Step 1: Record matching parenthesis pairs
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Step 2: Traverse string with direction switching
        string result = "";
        int curr = 0;
        int direction = 1; // 1 for right, -1 for left

        while (curr < n) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pair[curr];
                direction = -direction;
            } else {
                result += s[curr];
            }
            curr += direction;
        }

        return result;
    }
};