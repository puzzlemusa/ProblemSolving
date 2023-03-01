package LeetCode;


import java.util.Stack;

public class EvaluateReversePolishNotation {

    public static void main(String[] args) {
        System.out.println(evalRPN(new String[]{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}));
        System.out.println(evalRPN(new String[]{"4", "13", "5", "/", "+"}));
        System.out.println(evalRPN(new String[]{"2", "1", "+", "3", "*"}));
    }

    public static int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<>();
        for (String token : tokens) {
            if (token.equals("+")) {
                Integer op1 = stk.pop();
                Integer op2 = stk.pop();
                stk.push(op2 + op1);
            } else if (token.equals("-")) {
                Integer op1 = stk.pop();
                Integer op2 = stk.pop();
                stk.push(op2 - op1);
            } else if (token.equals("*")) {
                Integer op1 = stk.pop();
                Integer op2 = stk.pop();
                stk.push(op2 * op1);
            } else if (token.equals("/")) {
                Integer op1 = stk.pop();
                Integer op2 = stk.pop();
                stk.push(op2 / op1);
            } else {
                int i = Integer.parseInt(token);
                stk.push(i);
            }
        }

        return stk.pop();
    }
}
