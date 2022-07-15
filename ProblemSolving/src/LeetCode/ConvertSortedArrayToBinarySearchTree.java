package LeetCode;


public class ConvertSortedArrayToBinarySearchTree {

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
        //TreeNode res = sortedArrayToBST(new int[]{1});
        TreeNode res1 = sortedArrayToBST(new int[]{1, 2, 3, 4, 5});

        System.out.println("");
    }

    public static TreeNode sortedArrayToBST(int[] nums) {
        return construct(nums, 0, nums.length - 1);
    }

    public static TreeNode construct(int[] nums, int low, int high) {
        if (low > high)
            return null;

        //int mid = low + (high-low)/2; // avoids integer overflow
        int mid = (low + high) / 2;

        TreeNode node = new TreeNode(nums[mid]);
        node.left = construct(nums, low, mid - 1);
        node.right = construct(nums, mid + 1, high);
        return node;
    }
}
