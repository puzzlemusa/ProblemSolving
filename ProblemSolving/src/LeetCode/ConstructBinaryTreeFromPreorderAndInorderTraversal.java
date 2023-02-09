package LeetCode;


import java.util.HashMap;
import java.util.Map;

public class ConstructBinaryTreeFromPreorderAndInorderTraversal {

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
        TreeNode treeNode = buildTree(
                new int[]{1, 2, 4, 5, 3, 6, 7, 8, 9},
                new int[]{4, 2, 5, 1, 6, 3, 8, 7, 9}
        );

        TreeNode treeNode1 = buildTree(
                new int[]{3, 9, 20, 15, 7},
                new int[]{9, 3, 15, 20, 7}
        );
        TreeNode treeNode2 = buildTree(
                new int[]{1, 2},
                new int[]{2, 1}
        );
        System.out.println(treeNode.val);
    }

    private static int pi;
    private static Map<Integer, Integer> itemToPos;

    public static TreeNode buildTree(int[] preorder, int[] inorder) {
        itemToPos = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            itemToPos.put(inorder[i], i);
        }
        pi = 0;
        return formTree(preorder, 0, inorder.length - 1);
    }

    private static TreeNode formTree(int[] preorder, int left, int right) {
        if (left > right) {
            return null;
        }
        int item = preorder[pi++];
        TreeNode root = new TreeNode(item);

        root.left = formTree(preorder, left, itemToPos.get(item) - 1);
        root.right = formTree(preorder, itemToPos.get(item) + 1, right);
        return root;
    }
}
