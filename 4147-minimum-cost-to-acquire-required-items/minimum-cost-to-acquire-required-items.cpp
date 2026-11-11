#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        // Candidate 1: Buy 0 Type 3 items
        long long option1 = n1 * c1 + n2 * c2;

        // Candidate 2: Buy min(n1, n2) Type 3 items
        long long shared = min(n1, n2);
        long long option2 = shared * cb + (n1 - shared) * c1 + (n2 - shared) * c2;

        // Candidate 3: Buy max(n1, n2) Type 3 items
        long long maxNeed = max(n1, n2);
        long long option3 = maxNeed * cb;

        return min({option1, option2, option3});
    }
};