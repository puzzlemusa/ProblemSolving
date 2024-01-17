package LeetCode;


import java.util.Arrays;
import java.util.Comparator;

public class MeetingRooms {

    public static void main(String[] args) {
        System.out.println(canAttendMeetings(new int[][]{{0, 30}, {5, 10}, {15, 20}}));
        System.out.println(canAttendMeetings(new int[][]{{7, 10}, {2, 4}}));
    }

    // Time complexity: O(nlog(n)), space complexity: O(1)
    public static boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        for(int i=1; i<intervals.length; i++){
            int[] interval1 = intervals[i-1];
            int[] interval2 = intervals[i];

            if(interval1[1] > interval2[0]) return false;
        }
        return true;
    }
}
