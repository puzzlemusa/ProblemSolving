package LeetCode;


import java.util.*;

public class BinaryTreeTopDownView {

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
        one.right = three;
        two.left = four;
        two.right = five;
        three.right = six;
        five.left = seven;
        five.right = eight;

        System.out.println(topDown1(one));
    }

    // Time Complexity: O(n), space complexity: O(n)
    public static List<Integer> topDown(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Queue<TreeNode> Q = new LinkedList<>();
        Queue<Integer> distanceQ = new LinkedList<>();
        Map<Integer, TreeNode> distanceFromRootToNode = new HashMap<>();

        if (root == null)
            return result;

        Q.offer(root);
        distanceQ.offer(0);

        while (!Q.isEmpty()) {
            TreeNode node = Q.poll();
            int distance = distanceQ.poll();

            if (!distanceFromRootToNode.containsKey(distance)) {
                distanceFromRootToNode.put(distance, node);
            }

            if (node.left != null) {
                Q.offer(node.left);
                distanceQ.offer(distance - 1);
            }

            if (node.right != null) {
                Q.offer(node.right);
                distanceQ.offer(distance + 1);
            }
        }

        for (TreeNode node : distanceFromRootToNode.values()) {
            result.add(node.val);
        }

        return result;
    }

    private static List<Integer> topDown1(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        Map<Integer, Integer> horizontalDistanceToVal = new HashMap<>();
        int i = dfs(0, root, horizontalDistanceToVal) + 1;
        for (; horizontalDistanceToVal.containsKey(i); i++) {
            ans.add(horizontalDistanceToVal.get(i));
        }
        return ans;
    }

    private static int dfs(int horizontalDistance, TreeNode root, Map<Integer, Integer> map) {
        if (root == null) {
            return horizontalDistance;
        }
        map.putIfAbsent(horizontalDistance, root.val);
        return Math.min(dfs(horizontalDistance - 1, root.left, map), dfs(horizontalDistance + 1, root.right, map));
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
