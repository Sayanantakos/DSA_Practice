class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long c1 = cost1;
        long c2 = cost2;
        long cb = costBoth;
        long n1 = need1;
        long n2 = need2;

        // Candidate 1: Buy 0 Type 3 items
        long option1 = n1 * c1 + n2 * c2;

        // Candidate 2: Buy min(n1, n2) Type 3 items
        long shared = Math.min(n1, n2);
        long option2 = shared * cb + (n1 - shared) * c1 + (n2 - shared) * c2;

        // Candidate 3: Buy max(n1, n2) Type 3 items
        long maxNeed = Math.max(n1, n2);
        long option3 = maxNeed * cb;

        return Math.min(option1, Math.min(option2, option3));
    }
}