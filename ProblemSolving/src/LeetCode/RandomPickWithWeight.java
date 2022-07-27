package LeetCode;

import java.util.Random;

public class RandomPickWithWeight {

    public static void main(String[] args) {
        solution(new int[]{1, 3});
        System.out.println(pickIndex());
        System.out.println(pickIndex());
        System.out.println(pickIndex());
        System.out.println(pickIndex());
    }

    static Random rand;
    static int[] w_arr;

    public static void solution(int[] w) {
        rand = new Random();
        w_arr = new int[w.length];
        w_arr[0] = w[0];
        for (int i = 1; i < w.length; i++) {
            w_arr[i] = w_arr[i - 1] + w[i];
        }
    }

    public static int pickIndex() {
        int randomNumber = rand.nextInt(w_arr[w_arr.length - 1]);

        int low = 0;
        int high = w_arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (randomNumber == w_arr[mid]) {
                return mid;
            } else if (randomNumber > w_arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
}
