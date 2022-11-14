package LeetCode;


public class FirstBadVersion {

    public static void main(String[] args) {
        System.out.println(firstBadVersion(5));
    }

    public static int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == 1) {
                if (isBadVersion(mid))
                    return 1;
                else return 2;
            } else if (!isBadVersion(mid - 1) && isBadVersion(mid))
                return mid;
            else if (isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    public static boolean isBadVersion(int n) {
        return n >= 4;
    }
}
