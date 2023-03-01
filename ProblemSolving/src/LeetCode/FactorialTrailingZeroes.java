package LeetCode;


public class FactorialTrailingZeroes {

    public static void main(String[] args) {
        System.out.println(trailingZeroes(5));
        System.out.println(trailingZeroes(25));
        System.out.println(trailingZeroes(105));
    }

    public static int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
}
