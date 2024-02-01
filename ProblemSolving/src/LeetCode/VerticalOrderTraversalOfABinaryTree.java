package LeetCode;


import java.util.*;

public class VerticalOrderTraversalOfABinaryTree {

    public static void main(String[] args) {
        TreeNode one = new TreeNode(1);
        TreeNode two = new TreeNode(2);
        TreeNode three = new TreeNode(3);
        TreeNode four = new TreeNode(4);
        TreeNode five = new TreeNode(5);
        TreeNode six = new TreeNode(6);
        TreeNode seven = new TreeNode(7);
        TreeNode eight = new TreeNode(8);

        //        1
        //    2       3
        // 4     5        6
        //    7     8

        one.left = two;
        one.right = three;
        two.left = four;
        two.right = five;
        three.right = six;
        five.left = seven;
        five.right = eight;

        System.out.println(verticalTraversal(one));
    }

    // Time Complexity: O(log(n)), space complexity: O(n)
    private static List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        dfs(0, 0, root, map);
        for (TreeMap<Integer, PriorityQueue<Integer>> mp : map.values()) {
            List<Integer> list = new ArrayList<>();
            for (PriorityQueue<Integer> pq : mp.values()) {
                while (!pq.isEmpty()) {
                    list.add(pq.poll());
                }
            }
            ans.add(list);
        }
        return ans;
    }

    private static void dfs(int horizontalDistance, int height, TreeNode root, TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map) {
        if (root == null) {
            return;
        }
        if (!map.containsKey(horizontalDistance)) {
            map.put(horizontalDistance, new TreeMap<>());
        }
        if (!map.get(horizontalDistance).containsKey(height)) {
            map.get(horizontalDistance).put(height, new PriorityQueue<>());
        }
        map.get(horizontalDistance).get(height).offer(root.val);
        dfs(horizontalDistance - 1, height + 1, root.left, map);
        dfs(horizontalDistance + 1, height + 1, root.right, map);
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
