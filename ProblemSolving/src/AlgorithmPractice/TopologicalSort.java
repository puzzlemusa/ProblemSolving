package AlgorithmPractice;

import java.util.*;

public class TopologicalSort {

    public static void main(String[] args) {
        System.out.println(topologicalSort(Map.of(
                1, List.of(2, 3),
                2, List.of(4, 5),
                3, List.of(4),
                4, List.of(5),
                5, List.of()
        )));

        System.out.println(topologicalSort(Map.of(
                1, List.of(2, 3),
                2, List.of(4),
                3, List.of(4),
                4, List.of(5),
                5, List.of(2)
        )));
    }

    private static List<Integer> topologicalSort(Map<Integer, List<Integer>> adjacent) {
        Map<Integer, Integer> inDegree = new HashMap<>();
        for (Map.Entry entry : adjacent.entrySet()) {
            if (!inDegree.containsKey((int) entry.getKey())) {
                inDegree.put((int) entry.getKey(), 0);
            }
            for (int i : (List<Integer>) entry.getValue()) {
                if (inDegree.containsKey(i)) {
                    inDegree.put(i, inDegree.get(i) + 1);
                } else {
                    inDegree.put(i, 1);
                }
            }
        }
        List<Integer> nodeWithNoInDegree = new ArrayList<>();
        for (Map.Entry entry : inDegree.entrySet()) {
            if ((int) entry.getValue() == 0) {
                nodeWithNoInDegree.add((int) entry.getKey());
            }
        }
        List<Integer> topologicalOrder = new ArrayList<>();
        while (!nodeWithNoInDegree.isEmpty()) {
            int node = nodeWithNoInDegree.get(nodeWithNoInDegree.size() - 1);
            nodeWithNoInDegree.remove(nodeWithNoInDegree.size() - 1);
            topologicalOrder.add(node);
            for (int i : adjacent.get(node)) {
                inDegree.put(i, inDegree.get(i) - 1);
                if (inDegree.get(i) == 0) {
                    nodeWithNoInDegree.add(i);
                }
            }

        }

        if (topologicalOrder.size() == inDegree.size()) {
            return topologicalOrder;
        } else {
            return Collections.emptyList();
        }
    }
}
