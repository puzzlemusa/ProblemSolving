package LeetCode;


import java.util.LinkedList;
import java.util.Queue;

public class SymmetricTree {

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

        System.out.println(isSymmetric(one));
    }

    public static boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    public static boolean isMirror(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        }

        if (root1 != null && root2 != null) {
            return root1.val == root2.val && isMirror(root1.left, root2.right) && isMirror(root1.right, root2.left);
        }

        return false;
    }

    public static boolean isSymmetric1(TreeNode root) {
        Queue<TreeNode> Q = new LinkedList<>();

        if (root == null)
            return true;

        Q.add(root.left);
        Q.add(root.right);

        while (!Q.isEmpty()) {
            TreeNode left = Q.poll();
            TreeNode right = Q.poll();

            if (left == null && right == null)
                continue;

            if (left == null ^ right == null)
                return false;

            if(left.val != right.val)
                return false;

            Q.add(left.left);
            Q.add(right.right);
            Q.add(left.right);
            Q.add(right.left);
        }

        return true;
    }
}
