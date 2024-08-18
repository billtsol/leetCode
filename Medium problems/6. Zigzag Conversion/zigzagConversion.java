class Solution {
    public String convert(String s, int numRows) {
        int counter = s.length();
        if (counter <= 2 || numRows == 1) {
            return s;
        }

        String result = "";
        char[][] strT = new char[numRows][counter / 2 + 1];

        int row = -1;
        int col = 0;
        char temp;

        boolean goDown = true;

        for (int pos = 0; pos < counter; pos++) {

            if (goDown) {
                row++;
                if (row == numRows - 1) {
                    goDown = !goDown;
                }
            } else {
                row--;
                col++;
                if (row == 0) {
                    goDown = !goDown;
                }
            }

            temp = s.charAt(pos);

            strT[row][col] = temp;
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < counter / 2 + 1; j++) {
                if (strT[i][j] != '\u0000') {
                    result = result + strT[i][j];
                }
            }
        }

        return result;
    }
}