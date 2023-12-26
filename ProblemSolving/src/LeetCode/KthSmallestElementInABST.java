package LeetCode;


import java.util.ArrayDeque;
import java.util.Deque;

public class KthSmallestElementInABST {

    public static void main(String[] args) {
        TreeNode one = new TreeNode(1);
        TreeNode two = new TreeNode(2);
        TreeNode three = new TreeNode(3);
        TreeNode four = new TreeNode(4);
        TreeNode five = new TreeNode(5);
        TreeNode six = new TreeNode(6);
        TreeNode seven = new TreeNode(7);
        TreeNode eight = new TreeNode(8);

        two.left = one;
        three.left = two;
        three.right = two;
        five.left = three;
        five.right = six;

        System.out.println(kthSmallest(five, 3));
    }

    // Complexity: O(n)
    public static int kthSmallest(TreeNode root, int k) {
        Deque<TreeNode> d = new ArrayDeque<>();

        while (root != null || !d.isEmpty()) {
            while (root != null) {
                d.push(root);
                root = root.left;
            }

            root = d.poll();
            if (--k == 0) {
                break;
            }
            root = root.right;
        }

        return root.val;
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
