package LeetCode;


public class MergeTripletsToFormTargetTriplet {

    public static void main(String[] args) {
        System.out.println(mergeTriplets(new int[][]{{2, 5, 3}, {1, 8, 4}, {1, 7, 5}}, new int[]{2, 7, 5}));
        System.out.println(mergeTriplets(new int[][]{{3, 4, 5}, {4, 5, 6}}, new int[]{3, 2, 5}));
        System.out.println(mergeTriplets(new int[][]{{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}}, new int[]{5, 5, 5}));
    }

    // Time: O(n), Space: O(1)
    public static boolean mergeTriplets(int[][] triplets, int[] target) {
        int[] hopefulTriplet = new int[3];
        for (int i = 0; i < triplets.length; i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
            } else {
                hopefulTriplet[0] = Math.max(hopefulTriplet[0], triplets[i][0]);
                hopefulTriplet[1] = Math.max(hopefulTriplet[1], triplets[i][1]);
                hopefulTriplet[2] = Math.max(hopefulTriplet[2], triplets[i][2]);
            }
        }

        return hopefulTriplet[0] == target[0] && hopefulTriplet[1] == target[1]
                && hopefulTriplet[2] == target[2];
    }
}
