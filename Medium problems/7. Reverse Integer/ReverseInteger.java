class Solution {
    public int reverse(int x) {
        StringBuilder strX = new StringBuilder();
        strX.append(x);

        int i = 0;
        int j = strX.length() - 1;
        char tempC;

        if (x < 0) {
            i = 1;
        }

        while (i < j) {
            tempC = strX.charAt(i);
            strX.setCharAt(i, strX.charAt(j));
            strX.setCharAt(j, tempC);

            i++;
            j--;
        }

        Long check = Long.parseLong(strX.toString());
        if (check <= -Math.pow(2, 31) || check > Math.pow(2, 31)) {
            return 0;
        }

        return Integer.parseInt(strX.toString());

    }
}