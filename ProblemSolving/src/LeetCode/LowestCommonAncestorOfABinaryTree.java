package LeetCode;


public class LowestCommonAncestorOfABinaryTree {

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
        TreeNode zero = new TreeNode(0);
        TreeNode one = new TreeNode(1);
        TreeNode two = new TreeNode(2);
        TreeNode three = new TreeNode(3);
        TreeNode four = new TreeNode(4);
        TreeNode five = new TreeNode(5);
        TreeNode six = new TreeNode(6);
        TreeNode seven = new TreeNode(7);
        TreeNode eight = new TreeNode(8);
        TreeNode nine = new TreeNode(9);

        four.left = three;
        four.right = five;
        two.left = zero;
        two.right = four;
        eight.left = seven;
        eight.right = nine;
        six.left = two;
        six.right = eight;

        System.out.println(lowestCommonAncestor(six, two, eight).val);
        System.out.println(lowestCommonAncestor(six, two, four).val);
        System.out.println(lowestCommonAncestor(six, two, five).val);
        System.out.println(lowestCommonAncestor(six, five, seven).val);
        System.out.println(lowestCommonAncestor(six, seven, nine).val);
        System.out.println(lowestCommonAncestor(six, six, two).val);
        System.out.println(lowestCommonAncestor(six, two, six).val);
        System.out.println(lowestCommonAncestor(six, eight, two).val);
    }

    // Complexity: O(H) H = height of the tree.
    private static TreeNode res = null;

    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        traverse(root, p, q);
        return res;
    }

    public static boolean traverse(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return false;
        }
        boolean found = false;
        if (root == p || root == q) {
            found = true;
        }
        boolean leftFound = traverse(root.left, p, q);
        boolean rightFound = traverse(root.right, p, q);
        if (leftFound && rightFound) {
            res = root;
            return true;
        }
        if (found && (leftFound || rightFound)) {
            res = root;
            return true;
        }
        return found || leftFound || rightFound;
    }
}
