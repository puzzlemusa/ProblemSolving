package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class CombinationSum {

    public static void main(String[] args) {
        System.out.println(combinationSum(new int[]{2, 3, 6, 7}, 7));
        System.out.println(combinationSum(new int[]{2, 3, 5}, 8));
        System.out.println(combinationSum(new int[]{2}, 1));
    }

    // Complexity: O(2^(n+target))
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
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
            curr.add(candidates[start]);
            find(start, candidates, target - candidates[start], curr, res);
            curr.remove(curr.size() - 1);
            find(start + 1, candidates, target, curr, res);
        }
    }
}
