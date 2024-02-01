package LeetCode;


import java.util.Arrays;
import java.util.Comparator;

public class FindMaxBandWidth {

    public static void main(String[] args) {
        System.out.println(findMaxBandWidth(new int[][]{{1, 30, 2}, {31, 60, 4}, {61, 120, 3},
                {1, 20, 2}, {21, 40, 4}, {41, 60, 5}, {61, 120, 3},
                {1, 60, 4}, {61, 120, 4}}));
    }

    // Time complexity: O(nlong(n)), space complexity: O(n).
    public static int findMaxBandWidth(int[][] showInfos) {
        int[][] points= new int[showInfos.length * 2][2];
        int index = 0;
        for(int[] showInfo : showInfos) {
            points[index++] = new int[]{showInfo[0], showInfo[2]};
            points[index++] = new int[]{showInfo[1], -1 * showInfo[2]};
        }

        Arrays.sort(points, Comparator.comparingInt(a -> a[0]));
        int maxBandWidth = 0;
        int bandWidth = 0;
        for(int[] point : points) {
            bandWidth += point[1];
            maxBandWidth = Math.max(maxBandWidth, bandWidth);
        }

        return maxBandWidth;
    }
}
