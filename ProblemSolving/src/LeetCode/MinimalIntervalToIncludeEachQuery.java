package LeetCode;


import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class MinimalIntervalToIncludeEachQuery {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(minInterval(new int[][]{{1, 4}, {2, 4}, {3, 6}, {4, 4}}, new int[]{2, 3, 4, 5})));
        System.out.println(Arrays.toString(minInterval(new int[][]{{2, 3}, {2, 5}, {1, 8}, {20, 25}}, new int[]{2, 19, 5, 22})));
    }

    // Time complexity: O(nlog(n) + qlog(q)), space complexity: O(n + q)
    public static int[] minInterval(int[][] intervals, int[] queries) {
        Arrays.sort(intervals, Comparator.comparingInt(o -> o[0]));

        Query[] sortedQueries = new Query[queries.length];
        for (int i = 0; i < queries.length; i++) {
            sortedQueries[i] = new Query(queries[i], i);
        }

        Arrays.sort(sortedQueries, Comparator.comparingInt(q -> q.value));

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt((a -> a[1] - a[0] + 1)));
        int idx = 0;

        int[] results = new int[queries.length];
        for (Query query : sortedQueries) {
            while ((idx < intervals.length) && (query.value >= intervals[idx][0])) {
                pq.add(intervals[idx]);
                idx++;
            }
            while (!pq.isEmpty() && (pq.peek()[1] < query.value)) {
                pq.remove();
            }

            int[] res = pq.peek();
            int ans = pq.isEmpty() ? -1 : res[1] - res[0] + 1;
            results[query.index] = ans;
        }

        return results;
    }

    public record Query(int value, int index) {
    }

}

