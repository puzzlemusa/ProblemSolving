package LeetCode;


public class ValidParenthesisString {

    public static void main(String[] args) {
        System.out.println(checkValidString("()"));
        System.out.println(checkValidString("(*)"));
        System.out.println(checkValidString("(*))"));
    }

    public static boolean checkValidString(String s) {
        int cMin = 0;
        int cMax = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                cMin++;
                cMax++;
            } else if (s.charAt(i) == ')') {
                cMin--;
                cMax--;
            } else {
                cMin--;
                cMax++;
            }
            if (cMax < 0) {
                return false;
            }
            cMin = Math.max(cMin, 0);
        }

        return cMin == 0;
    }
}
