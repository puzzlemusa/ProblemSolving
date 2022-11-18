package LeetCode;


public class LowestCommonAncestorOfABinarySearchTree {

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
        System.out.println(lowestCommonAncestor(six, five, seven).val);
        System.out.println(lowestCommonAncestor(six, seven, nine).val);
        System.out.println(lowestCommonAncestor(six, six, two).val);
        System.out.println(lowestCommonAncestor(six, two, six).val);
        System.out.println(lowestCommonAncestor(six, eight, two).val);
    }

    // Complexity: O(H) H = height of the tree.
    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val == p.val) {
            return p;
        } else if (root.val == q.val) {
            return q;
        } else if ((p.val < root.val && root.val < q.val) || (p.val > root.val && root.val > q.val)) {
            return root;
        } else if (p.val < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        } else {
            return lowestCommonAncestor(root.right, p, q);
        }
    }
}
