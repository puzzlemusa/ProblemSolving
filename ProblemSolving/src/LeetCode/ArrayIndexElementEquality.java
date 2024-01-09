package LeetCode;


public class ArrayIndexElementEquality {
    public static void main(String[] args) {
        System.out.println(indexEqualsValueSearch1(new int[]{-8, 0, 4, 5, 6}));
        System.out.println(indexEqualsValueSearch1(new int[]{-8, 0, 2, 5}));
        System.out.println(indexEqualsValueSearch1(new int[]{-1, 0, 3, 6}));
        System.out.println(indexEqualsValueSearch1(new int[]{1, 2, 3, 4, 5}));
        System.out.println(indexEqualsValueSearch1(new int[]{0, 2, 3, 4, 5}));
        System.out.println(indexEqualsValueSearch1(new int[]{0, 1, 2, 3, 4, 5}));
        System.out.println(indexEqualsValueSearch1(new int[]{-8, 0, 1, 3, 5}));
    }

    // https://www.pramp.com/challenge/jKoA5GAVy9Sr9jGBjz04
    // Time: O(log(n)), space: O(1)
    static int indexEqualsValueSearch(int[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == mid) {
                if (mid == 0) {
                    return 0;
                } else if (arr[mid - 1] != mid - 1) {
                    return mid;
                }
            }
            if (arr[mid] < mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    static int indexEqualsValueSearch1(int[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mid <= arr[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return arr[left] == left ? left : -1;
    }
}
