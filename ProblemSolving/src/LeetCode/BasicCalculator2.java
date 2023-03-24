package LeetCode;


public class BasicCalculator2 {

    public static void main(String[] args) {
        System.out.println(calculate("42"));
        System.out.println(calculate("3+2*2"));
        System.out.println(calculate(" 3/2 "));
        System.out.println(calculate(" 3+5 / 2 "));
    }

    public static int calculate(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        int currentNumber = 0;
        int lastNumber = 0;
        int total = 0;
        char operator = '+';
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            if (Character.isDigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!Character.isDigit(currentChar) && !Character.isWhitespace(currentChar) || i == s.length() - 1) {
                if (operator == '+' || operator == '-') {
                    total += lastNumber;
                    lastNumber = (operator == '+') ? currentNumber : -currentNumber;
                } else if (operator == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (operator == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                operator = currentChar;
                currentNumber = 0;
            }
        }
        total += lastNumber;
        return total;
    }
}
