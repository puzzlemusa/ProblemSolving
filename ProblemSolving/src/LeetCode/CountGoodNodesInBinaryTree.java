package LeetCode;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class CountGoodNodesInBinaryTree {

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

        goodNodes(one);
    }

    // Complexity: O(n)
    public static int goodNodes(TreeNode root) {
        return find(root, -100000);
    }

    private static int find(TreeNode root, int maxSoFar){
        if(root == null){
            return 0;
        }

        int i = 0;
        if(root.val >= maxSoFar){
            i++;
            maxSoFar = root.val;
        }

        return i + find(root.left, maxSoFar) + find(root.right, maxSoFar);
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
