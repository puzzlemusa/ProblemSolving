package LeetCode;


import java.util.*;

public class MergeIntervals {

    public static void main(String[] args) {
        System.out.println(Arrays.deepToString(merge(new int[][]{{1, 3}, {2, 6}, {8, 10}, {15, 18}})));
        System.out.println(Arrays.deepToString(merge(new int[][]{{8, 10}, {1, 3}, {2, 6}, {15, 18}})));
        System.out.println(Arrays.deepToString(merge(new int[][]{{8, 10}, {1, 3}, {2, 6}, {2, 3}, {15, 18}})));
        System.out.println(Arrays.deepToString(merge(new int[][]{{1, 4}, {4, 5}})));
    }

    public static int[][] merge(int[][] intervals) {
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            list.add(new AbstractMap.SimpleEntry<>(intervals[i][0], intervals[i][1]));
        }

        list.sort(Comparator.comparingInt((Map.Entry::getKey)));

        List<List<Integer>> res = new ArrayList<>();
        for (Map.Entry entry : list) {
            if (res.isEmpty()) {
                res.add(new ArrayList<>() {{
                    add((Integer) entry.getKey());
                    add((Integer) entry.getValue());
                }});
            } else {
                int lastEnd = res.get(res.size() - 1).get(1);
                int entryStart = (int) entry.getKey();
                int entryEnd = (int) entry.getValue();
                if (entryStart <= lastEnd) {
                    if (entryEnd > lastEnd) {
                        res.get(res.size() - 1).set(1, entryEnd);
                    }
                } else {
                    res.add(new ArrayList<>() {{
                        add((Integer) entry.getKey());
                        add((Integer) entry.getValue());
                    }});
                }
            }
        }
        int[][] r = new int[res.size()][2];
        for (int i = 0; i < res.size(); i++) {
            r[i][0] = res.get(i).get(0);
            r[i][1] = res.get(i).get(1);
        }

        return r;
    }

    // Clean code
    public int[][] merge1(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        LinkedList<int[]> merged = new LinkedList<>();
        for (int[] interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.isEmpty() || merged.getLast()[1] < interval[0]) {
                merged.add(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.getLast()[1] = Math.max(merged.getLast()[1], interval[1]);
            }
        }
        return merged.toArray(new int[merged.size()][]);
    }

    // Time complexity : O(nlogn), space complexity : O(n)
    public static int[][] merge2(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        List<int[]> il = new ArrayList<>();
        Collections.addAll(il, intervals);

        for(int i=1; i<il.size(); i++){
            int[] int1 = il.get(i-1);
            int[] int2 = il.get(i);

            if(int1[1] >= int2[0]){
                int[] mergedInt = new int[] {
                        Math.min(int1[0], int2[0]),
                        Math.max(int1[1], int2[1])
                };
                il.remove(int1);
                il.remove(int2);
                il.add(i-1, mergedInt);
                i--;
            }
        }

        return il.toArray(new int [il.size()][]);
    }
}
