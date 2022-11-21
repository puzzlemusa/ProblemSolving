package LeetCode;


import java.util.Stack;
import java.util.stream.Collectors;

public class DecodeString {

    public static void main(String[] args) {
        System.out.println(decodeString("3[a]2[bc]"));
        System.out.println(decodeString("3[a2[c]]"));
        System.out.println(decodeString("zz3[a2[c]]"));
        System.out.println(decodeString("2[abc]3[cd]ef"));
        System.out.println(decodeString("9[a]"));
        System.out.println(decodeString("0[a]"));
    }

    public static String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            if (ch == '[') {
                String number = "";
                while (i > 0) {
                    if (isNumber(s.charAt(i - 1))) {
                        number = s.charAt(i - 1) + number;
                        i--;
                    } else {
                        break;
                    }
                }
                int freq = Integer.parseInt(number);
                String text = "";
                while (stack.peek() != ']') {
                    text = stack.pop() + text;
                }
                stack.pop();
                for (int j = 0; j < freq; j++) {
                    stack.addAll(text.chars().mapToObj(e -> (char) e).collect(Collectors.toList()));
                }
            } else {
                stack.push(ch);
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        while (!stack.isEmpty()){
            stringBuilder.append(stack.pop());
        }
        return stringBuilder.toString();
    }

    private static boolean isNumber(char c) {
        return c - '0' < 10;
    }
}
