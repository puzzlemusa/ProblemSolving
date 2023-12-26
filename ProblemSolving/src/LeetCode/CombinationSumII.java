package LeetCode;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSumII {

    public static void main(String[] args) {
        System.out.println(combinationSum2(new int[]{10, 1, 2, 7, 6, 1, 5}, 8));
        System.out.println(combinationSum2(new int[]{2, 5, 2, 1, 2}, 5));
    }

    // Complexity: O(2^(n))
    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        find(0, candidates, target, curr, res);
        return res;
    }

    private static void find(int start, int[] candidates, int target, List<Integer> curr, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(curr));
        } else if (target < 0 || start >= candidates.length) {
        } else {
            for (int i = start; i < candidates.length; i++) {
                if (i > start && candidates[i] == candidates[i - 1]) {
                } else {
                    curr.add(candidates[i]);
                    find(i + 1, candidates, target - candidates[i], curr, res);
                    curr.remove(curr.size() - 1);
                }
            }
        }
    }
}
