package LeetCode;


public class ValidateBinarySearchTree {

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
        TreeNode three = new TreeNode(3);
        TreeNode four = new TreeNode(4);
        TreeNode five = new TreeNode(5);
        TreeNode six = new TreeNode(6);
        TreeNode seven = new TreeNode(7);
        TreeNode eight = new TreeNode(8);

        five.left = four;
        five.right = six;
        six.left = three;
        six.right = seven;

        System.out.println(isValidBST(five));
    }

    public static boolean isValidBST(TreeNode root) {
        return findValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public static boolean findValid(TreeNode root, long min, long max) {
        if (root == null) {
            return true;
        }
        if ((root.val >= max) || (root.val <= min))
            return false;

        return findValid(root.left, min, root.val) && findValid(root.right, root.val, max);
    }
}
