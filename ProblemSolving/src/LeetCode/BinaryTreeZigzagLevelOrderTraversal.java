package LeetCode;


import java.util.*;

public class BinaryTreeZigzagLevelOrderTraversal {

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
        TreeNode nine = new TreeNode(9);

        one.left = two;
        one.right = three;
        two.left = four;
        two.right = five;
        three.left = six;
        three.right = seven;
        seven.left = eight;
        seven.right = nine;

        System.out.println(zigzagLevelOrder(one));
    }

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Queue<TreeNode> Q = new LinkedList<>();
        Q.add(root);
        boolean leftToRight = true;
        while (!Q.isEmpty()) {
            List<Integer> level = new ArrayList<>();
            int currentLvlItem = Q.size();
            for (int i = 0; i < currentLvlItem; i++) {
                TreeNode treeNode = Q.poll();
                level.add(treeNode.val);
                if (treeNode.left != null) {
                    Q.add(treeNode.left);
                }
                if (treeNode.right != null) {
                    Q.add(treeNode.right);
                }
            }
            if(!leftToRight){
                Collections.reverse(level);
            }
            leftToRight = !leftToRight;
            res.add(level);
        }

        return res;
    }
}
