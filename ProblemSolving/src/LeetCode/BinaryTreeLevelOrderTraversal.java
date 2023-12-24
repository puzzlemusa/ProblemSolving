package LeetCode;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class BinaryTreeLevelOrderTraversal {

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


    public static void main(String[] args) {
        TreeNode one = new TreeNode(1);
        TreeNode two = new TreeNode(2);
        TreeNode two1 = new TreeNode(2);
        TreeNode three = new TreeNode(3);
        TreeNode three1 = new TreeNode(3);
        TreeNode four = new TreeNode(4);
        TreeNode four1 = new TreeNode(4);
        TreeNode five = new TreeNode(5);
        TreeNode six = new TreeNode(6);
        TreeNode seven = new TreeNode(7);
        TreeNode eight = new TreeNode(8);

        one.left = two;
        one.right = two1;
        two.left = three;
        //two.right = four;
        two1.left = three1;
        //two1.right = three1;

        levelOrder(one);
    }

    // Complexity: O(n)
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        Queue<TreeNode> Q = new LinkedList<>();

        if (root == null)
            return result;

        Q.offer(root);

        while (!Q.isEmpty()) {
            int level = Q.size();

            List<Integer> levelValues = new ArrayList<>();
            for (int i = 0; i < level; i++) {
                if (Q.peek().left != null)
                    Q.offer(Q.peek().left);
                if (Q.peek().right != null)
                    Q.offer(Q.peek().right);

                levelValues.add(Q.poll().val);
            }
            result.add(levelValues);
        }

        return result;
    }
}
