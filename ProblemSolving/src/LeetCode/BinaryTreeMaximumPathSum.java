package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class BinaryTreeMaximumPathSum {


    public static void main(String[] args) {
        TreeNode one = new TreeNode(1);
        TreeNode two = new TreeNode(2);
        TreeNode three = new TreeNode(3);
        TreeNode four = new TreeNode(4);
        TreeNode five = new TreeNode(5);
        TreeNode six = new TreeNode(6);
        TreeNode seven = new TreeNode(7);
        TreeNode eight = new TreeNode(8);

        one.left = two;
        two.left = three;
        two.right = four;

        System.out.println(maxPathSum(one));
    }

    static int max;

    // Time complexity: O(n), space complexity: O(n)
    public static int maxPathSum(TreeNode root) {
        max = Integer.MIN_VALUE;
        calc(root);
        return max;
    }

    private static int calc(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = Math.max(0, calc(root.left));
        int right = Math.max(0, calc(root.right));

        max = Math.max(max, left + right + root.val);
        return Math.max(left, right) + root.val;
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
