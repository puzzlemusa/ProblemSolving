package LeetCode;


public class BalancedBinaryTree {

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

        //two.left = four;
        //two.right = five;
        one.left = two;
        //one.right = three;

        System.out.println(isBalanced(one));
    }

    private static boolean isBalanced;
    public static boolean isBalanced(TreeNode root) {
        isBalanced = true;
        findHeight(root);
        return isBalanced;
    }

    private static int findHeight(TreeNode root){
        if(root == null){
            return 0;
        }

        int leftHeight = findHeight(root.left);
        int rightHeight = findHeight(root.right);

        isBalanced = isBalanced && Math.abs(leftHeight - rightHeight) <= 1;
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
