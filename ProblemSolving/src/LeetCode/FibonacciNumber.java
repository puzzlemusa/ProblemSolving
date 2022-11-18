package LeetCode;

public class FibonacciNumber {
    public static void main(String[] args) {
        System.out.println(fib(0));
        System.out.println(fib(1));
        System.out.println(fib(2));
        System.out.println(fib(8));
    }

    public static int fib(int n) {
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }
        return fib(n-1) + fib(n-2);
    }
}
