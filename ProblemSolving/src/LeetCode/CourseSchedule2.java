package LeetCode;


import java.util.*;

public class CourseSchedule2 {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(findOrder(2, new int[][]{{1, 0}})));
        System.out.println(Arrays.toString(findOrder(2, new int[][]{{0, 1}})));
        System.out.println(Arrays.toString(findOrder(2, new int[][]{{1, 0}, {0, 1}})));
        System.out.println(Arrays.toString(findOrder(4, new int[][]{{1, 0}, {2, 0}, {3, 1}, {3, 2}})));
        System.out.println(Arrays.toString(findOrder(1, new int[][]{})));
    }

    // Time complexity: O(V + E), space complexity: O(V + E)
    public static int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[] adj = new ArrayList[numCourses];
        int[] inDegree = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] prerequisite : prerequisites) {
            adj[prerequisite[1]].add(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        Queue<Integer> Q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                Q.offer(i);
            }
        }
        List<Integer> order = new ArrayList();
        while (!Q.isEmpty()) {
            int course = Q.poll();
            order.add(course);
            for (int depdendantCourse : adj[course]) {
                if (--inDegree[depdendantCourse] == 0) {
                    Q.offer(depdendantCourse);
                }
            }
        }

        if (order.size() == numCourses) {
            return order.stream().mapToInt(Integer::intValue).toArray();
        } else {
            return new int[0];
        }
    }
}
