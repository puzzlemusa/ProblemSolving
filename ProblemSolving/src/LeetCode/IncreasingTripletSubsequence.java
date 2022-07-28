package LeetCode;

public class IncreasingTripletSubsequence {
    public static void main(String[] args) {
        System.out.println(increasingTriplet(new int[]{2, 1, 5, 0, 4, 6}));
    }

    public static boolean increasingTriplet(int[] nums) {
        int low = Integer.MAX_VALUE;
        int mid = Integer.MAX_VALUE;

        for (int n : nums) {
            if(n<=low)
                low = n;
            else if(n<=mid)
                mid = n;
            else
                return true;
        }

        return false;
    }
}
