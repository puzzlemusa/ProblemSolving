package LeetCode;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class CourseSchedule {

    public static void main(String[] args) {
        System.out.println(canFinish(2, new int[][]{{1, 0}}));
        System.out.println(canFinish(2, new int[][]{{0, 1}}));
        System.out.println(canFinish(2, new int[][]{{1, 0}, {0, 1}}));
    }

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
}
