package LeetCode;


public class PowerOfThree {

    public static void main(String[] args) {
        System.out.println(isPowerOfThree(0));
        System.out.println(isPowerOfThree(27));
        System.out.println(isPowerOfThree(1));
        System.out.println(isPowerOfThree(-1));
        System.out.println(isPowerOfThree(2147483647));
    }

    public static boolean isPowerOfThree(int n) {
        long tot = 1;
        while(tot < n){
            tot *= 3;
        }

        return tot == n;
    }
}
