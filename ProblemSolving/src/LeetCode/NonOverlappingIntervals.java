package LeetCode;


import java.util.Arrays;
import java.util.Comparator;

public class NonOverlappingIntervals {

    public static void main(String[] args) {
        System.out.println(eraseOverlapIntervals(new int[][]{{1, 2}, {2, 3}, {3, 4}, {1, 3}}));
        System.out.println(eraseOverlapIntervals(new int[][]{{1, 2}, {1, 2}, {1, 2}}));
        System.out.println(eraseOverlapIntervals(new int[][]{{1, 2}, {2, 3}}));
    }

    public static int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        int[] prevInt = intervals[0];
        int intervalRemoved = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (prevInt[1] > intervals[i][0]) {
                intervalRemoved++;
                if (prevInt[1] > intervals[i][1]) {
                    prevInt = intervals[i];
                }
            } else {
                prevInt = intervals[i];
            }
        }

        return intervalRemoved;
    }
}
