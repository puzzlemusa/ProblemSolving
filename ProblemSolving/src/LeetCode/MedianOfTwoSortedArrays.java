package LeetCode;


public class MedianOfTwoSortedArrays {

    public static void main(String[] args) {
        System.out.println(findMedianSortedArrays(new int[]{1, 3}, new int[]{2}));
        System.out.println(findMedianSortedArrays(new int[]{1, 2}, new int[]{3, 4}));
        System.out.println(findMedianSortedArrays(new int[]{1, 2, 3}, new int[]{4, 5, 6}));
        System.out.println(findMedianSortedArrays(new int[]{1, 7}, new int[]{2, 3, 4, 5, 6}));
    }

    // Time: O(log(min(m,n))), space: O(1)
    public static double findMedianSortedArrays(int[] numsA, int[] numsB) {
        if (numsA.length > numsB.length) {
            return findMedianSortedArrays(numsB, numsA);
        }

        int m = numsA.length;
        int n = numsB.length;
        int total = m + n;
        int half = (total + 1) / 2;
        int left = 0;
        int right = m;

        while (left <= right) {
            int parititionA = (left + right) / 2;
            int parititionB = half - parititionA;

            int maxLeftA = parititionA == 0 ? Integer.MIN_VALUE : numsA[parititionA - 1];
            int minRightA = parititionA == m ? Integer.MAX_VALUE : numsA[parititionA];
            int maxLeftB = parititionB == 0 ? Integer.MIN_VALUE : numsB[parititionB - 1];
            int minRightB = parititionB == n ? Integer.MAX_VALUE : numsB[parititionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if (total % 2 == 0) {
                    return (Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB)) / 2.0;
                } else {
                    return Math.max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = parititionA - 1;
            } else {
                left = parititionA + 1;
            }
        }

        return 0.0;
    }

    // Time: O(m+n), space: O(m+n)
    public double findMedianSortedArrays1(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[] nums = new int[m + n];
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) nums[k++] = nums1[i++];
            else nums[k++] = nums2[j++];
        }
        for (; i < m; i++) nums[k++] = nums1[i];
        for (; j < n; j++) nums[k++] = nums2[j];
        if ((m + n) % 2 == 0) {
            return ((float) nums[(m + n - 1) / 2] + (float) nums[(m + n) / 2]) / (float) 2;
        } else return (float) nums[(m + n - 1) / 2];
    }
}
