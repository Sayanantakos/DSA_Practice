class Solution {
public:
    bool canAliceWin(int n) {
        int toRemove = 10;
        bool aliceTurn = true;

        while (n >= toRemove) {
            n -= toRemove;
            toRemove--;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};