class Solution {
    public boolean canAliceWin(int n) {
        int toRemove = 10;
        boolean aliceTurn = true;

        while (n >= toRemove) {
            n -= toRemove;
            toRemove--;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
}