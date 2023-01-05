package LeetCode;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class BinaryTreeInorderTraversal {

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

        System.out.println(inorderTraversal(one));
    }

    public static List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        calc(root, res);
        return res;
    }

    private static void calc(TreeNode root, List<Integer> res){
        if(root == null){
            return;
        }
        calc(root.left, res);
        res.add(root.val);
        calc(root.right, res);
    }
}
