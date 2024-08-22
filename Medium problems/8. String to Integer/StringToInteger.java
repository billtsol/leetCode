class Solution {
    public int myAtoi(String s) {

        String newS = "";
        char tempC;

        for (int i = 0; i < s.length(); i++) {
            tempC = s.charAt(i);

            if (tempC == '-' || tempC == '+') {
                if (newS.length() != 0) { // Number is before the symbol
                    break;
                }
                newS = newS + tempC;
            } else if (tempC != ' ') {
                if (tempC - '0' >= 0 && tempC - '0' < 10) { // tempC is Number
                    newS = newS + tempC;
                } else { // Stop if is a Char
                    break;
                }
            } else if (newS.length() >= 1) {
                break;
            }
        }

        if (newS.length() == 0) {
            return 0;
        }

        if (newS.equals("+") || newS.equals("-")) {
            return 0;
        }
        Double number = Double.parseDouble(newS.toString());

        if (number <= -Math.pow(2, 31)) {
            return (int) -Math.pow(2, 31);
        }
        if (number > Math.pow(2, 31)) {
            return (int) Math.pow(2, 31);
        }

        return (int) Math.floor(number);
    }
}