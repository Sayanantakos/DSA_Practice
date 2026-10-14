class Solution {
    public String maxSumOfSquares(int num, int sum) {
        int count9 = sum / 9;
        int rem = sum % 9;
        int needed = count9 + (rem > 0 ? 1 : 0);

        // Impossible if required digits exceed allowed length
        if (needed > num) {
            return "";
        }

        StringBuilder sb = new StringBuilder();
        
        // Place maximum possible '9's
        for (int i = 0; i < count9; i++) {
            sb.append('9');
        }
        
        // Place remainder digit if present
        if (rem > 0) {
            sb.append(rem);
        }
        
        // Pad remaining positions with '0's
        int zeros = num - needed;
        for (int i = 0; i < zeros; i++) {
            sb.append('0');
        }

        return sb.toString();
    }
}