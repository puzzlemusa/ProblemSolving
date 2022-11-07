package LeetCode;

public class RomanToInteger {
    public static void main(String[] args) {
        System.out.println(romanToInt("IV"));
        System.out.println(romanToInt("IX"));
        System.out.println(romanToInt("XL"));
        System.out.println(romanToInt("XC"));
        System.out.println(romanToInt("CD"));
        System.out.println(romanToInt("CM"));
        System.out.println(romanToInt("XII"));
        System.out.println(romanToInt("XXVII"));
        System.out.println(romanToInt("III"));
        System.out.println(romanToInt("LVIII"));
        System.out.println(romanToInt("MCMXCIV"));

    }

    public static int romanToInt(String s) {
        int res = 0;
        int currentDigit = 0;
        int lastDigit = 1001;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'M')
                currentDigit = 1000;
            else if (s.charAt(i) == 'D')
                currentDigit = 500;
            else if (s.charAt(i) == 'C')
                currentDigit = 100;
            else if (s.charAt(i) == 'L')
                currentDigit = 50;
            else if (s.charAt(i) == 'X')
                currentDigit = 10;
            else if (s.charAt(i) == 'V')
                currentDigit = 5;
            else if (s.charAt(i) == 'I')
                currentDigit = 1;

            if (currentDigit > lastDigit)
                res += (currentDigit - lastDigit - lastDigit);
            else
                res += currentDigit;
            lastDigit = currentDigit;
        }
        return res;
    }
}
