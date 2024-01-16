package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class SerializeAndDeserializeBinaryTree {


    private static int curr;

    public static void main(String[] args) {
        TreeNode one = new TreeNode(1);
        TreeNode two = new TreeNode(2);
        TreeNode three = new TreeNode(3);
        TreeNode four = new TreeNode(4);
        TreeNode five = new TreeNode(5);
        TreeNode six = new TreeNode(6);
        TreeNode seven = new TreeNode(7);
        TreeNode eight = new TreeNode(8);

        one.left = two;
        two.left = three;
        two.right = four;

        System.out.println(serialize(one));
    }

    // Time complexity: O(n), space complexity: O(n)
    public static String serialize(TreeNode root) {
        List<String> res = new ArrayList<>();
        DFSSer(root, res);
        return String.join(",", res);
    }

    private static void DFSSer(TreeNode root, List<String> res) {
        if (root == null) {
            res.add("null");
            return;
        }
        res.add(String.valueOf(root.val));
        DFSSer(root.left, res);
        DFSSer(root.right, res);
    }

    // Time complexity: O(n), space complexity: O(n)
    public static TreeNode deserialize(String data) {
        String[] arr = data.split(",");
        curr = 0;
        return DFSDes(arr);
    }

    private static TreeNode DFSDes(String[] arr) {
        if (arr[curr].equals("null")) {
            curr++;
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(arr[curr]));
        curr++;
        root.left = DFSDes(arr);
        root.right = DFSDes(arr);
        return root;
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
