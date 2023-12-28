package LeetCode;


import java.util.*;

public class CourseSchedule {

    public static void main(String[] args) {
        System.out.println(canFinish(2, new int[][]{{1, 0}}));
        System.out.println(canFinish(2, new int[][]{{0, 1}}));
        System.out.println(canFinish(2, new int[][]{{1, 0}, {0, 1}}));
        System.out.println(canFinish1(2, new int[][]{{1, 0}, {0, 1}}));
        System.out.println(canFinish1(2, new int[][]{{0, 1}, {1, 2}, {2, 3}}));
    }

    // Time complexity: O(V + E), space complexity: O(V + E)
    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] adjacentList = new ArrayList[numCourses];
        int[] inDegrees = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adjacentList[i] = new ArrayList<>();
        }

        for (int[] prerequisite : prerequisites) {
            adjacentList[prerequisite[1]].add(prerequisite[0]);
            inDegrees[prerequisite[0]]++;
        }

        Queue<Integer> Q = new LinkedList<>();
        for (int i = 0; i < inDegrees.length; i++) {
            if (inDegrees[i] == 0) {
                Q.offer(i);
            }
        }

        int count = 0;
        while (!Q.isEmpty()) {
            int course = Q.poll();
            count++;
            for (int adjacent : adjacentList[course]) {
                if (--inDegrees[adjacent] == 0) {
                    Q.offer(adjacent);
                }
            }
        }

        return count == numCourses;
    }

    public static boolean canFinish1(int numCourses, int[][] prerequisites) {
        Map<Integer, Integer> inDegree = new HashMap<>();
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] pre : prerequisites) {
            if (!inDegree.containsKey(pre[0])) {
                inDegree.put(pre[0], 1);
            } else {
                inDegree.put(pre[0], inDegree.get(pre[0]) + 1);
            }
            if (!inDegree.containsKey(pre[1])) {
                inDegree.put(pre[1], 0);
            }
            if (!adj.containsKey(pre[1])) {
                List<Integer> ad = new ArrayList<>();
                ad.add(pre[0]);
                adj.put(pre[1], ad);
            } else {
                List<Integer> ad = adj.get(pre[1]);
                ad.add(pre[0]);
                adj.put(pre[1], ad);
            }
            if (!adj.containsKey(pre[0])) {
                adj.put(pre[0], new ArrayList<>());
            }
        }

        List<Integer> zeroDegree = new ArrayList<>();
        for (Map.Entry entry : inDegree.entrySet()) {
            if ((int) entry.getValue() == 0) {
                zeroDegree.add((int) entry.getKey());
            }
        }

        List<Integer> sorted = new ArrayList<>();
        while (!zeroDegree.isEmpty()) {
            int node = zeroDegree.get(zeroDegree.size() - 1);
            sorted.add(node);
            zeroDegree.remove(zeroDegree.size() - 1);
            for (int ad : adj.get(node)) {
                inDegree.put(ad, inDegree.get(ad) - 1);
                if (inDegree.get(ad) == 0) {
                    zeroDegree.add(ad);
                }
            }
        }

        return sorted.size() == inDegree.size();
    }
}
