package LeetCode;


import java.util.Stack;

public class BackspaceStringCompare {

    public static void main(String[] args) {
        System.out.println(backspaceCompare("ab#c", "ad#c"));
        System.out.println(backspaceCompare("ab##", "c#d#"));
        System.out.println(backspaceCompare("a#c", "b"));
        System.out.println(backspaceCompare("#c", "#####c"));
    }

    public static boolean backspaceCompare(String s, String t) {
        String s_ = getString(s);
        String t_ = getString(t);

        return s_.equals(t_);
    }

    private static String getString(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '#') {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                stack.push(s.charAt(i));
            }
        }
        return String.valueOf(stack);
    }
}
