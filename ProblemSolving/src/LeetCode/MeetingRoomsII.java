package LeetCode;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class MeetingRoomsII {

    public static void main(String[] args) {
        System.out.println(minMeetingRooms1(new ArrayList<>() {
            {
                add(new Interval(0, 30));
                add(new Interval(5, 10));
                add(new Interval(15, 20));
            }
        }));
        System.out.println(minMeetingRooms1(new ArrayList<>() {
            {
                add(new Interval(7, 10));
                add(new Interval(2, 4));
            }
        }));
    }

    // Time complexity: O(nlog(n)), space complexity: O(n)
    public static int minMeetingRooms(List<Interval> intervals) {
        intervals.sort(Comparator.comparingInt(a -> a.start));
        List<Interval> rooms = new ArrayList<>();
        for (int i = 0; i < intervals.size(); i++) {
            if (rooms.isEmpty()) {
                rooms.add(intervals.get(i));
            } else {
                Interval interval1 = rooms.get(rooms.size() - 1);
                Interval interval2 = intervals.get(i);
                if (interval1.end > interval2.start) {
                    rooms.add(intervals.get(i));
                }
            }
        }
        return rooms.size();
    }

    // Time complexity: O(nlog(n)), space complexity: O(1)
    public static int minMeetingRooms1(List<Interval> intervals) {
        int start[] = new int[intervals.size()];
        int end[] = new int[intervals.size()];
        for (Interval interval : intervals) {
            start[intervals.indexOf(interval)] = interval.start;
            end[intervals.indexOf(interval)] = interval.end;
        }
        Arrays.sort(start);
        Arrays.sort(end);

        int rooms = 0;
        int startPointer = 0;
        int endPointer = 0;
        int minRooms = 0;
        while (startPointer < intervals.size()) {
            if (start[startPointer] < end[endPointer]) {
                rooms++;
                startPointer++;
            } else {
                rooms--;
                endPointer++;
            }
            minRooms = Math.max(minRooms, rooms);
        }
        return minRooms;
    }


}
