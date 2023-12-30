package LeetCode;


import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class KClosestPointsToOrigin {

    public static void main(String[] args) {
        System.out.println(Arrays.deepToString(kClosest(new int[][]{{1, 3}, {-2, 2}}, 1)));
        System.out.println(Arrays.deepToString(kClosest(new int[][]{{3, 3}, {5, -1}, {-2, 4}}, 2)));
        System.out.println(Arrays.deepToString(kClosest(new int[][]{{3, 3}, {1, -1}, {-1, 1}, {2, 2}}, 3)));
    }

    // Time complexity: O(klogn), space complexity: O(n)
    public static int[][] kClosest(int[][] points, int k) {
        Queue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> (a[0] * a[0] + a[1] * a[1])));

        for (int[] point : points) {
            minHeap.offer(point);
        }

        int[][] res = new int[k][];
        int n = 0;
        while (k-- > 0) {
            int[] dis = minHeap.poll();
            res[n++] = new int[]{dis[0], dis[1]};
        }

        return res;
    }
}
