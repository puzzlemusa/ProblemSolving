package LeetCode;

import java.util.*;

public class ReconstructItinerary {
    public static void main(String[] args) {
        System.out.println(findItinerary(List.of(List.of("JFK", "KUL"), List.of("JFK", "NRT"), List.of("NRT", "JFK"))));
        System.out.println(findItinerary(List.of(List.of("MUC", "LHR"), List.of("JFK", "MUC"), List.of("SFO", "SJC"), List.of("LHR", "SFO"))));
        System.out.println(findItinerary(List.of(List.of("JFK", "SFO"), List.of("JFK", "ATL"), List.of("SFO", "ATL"), List.of("ATL", "JFK"), List.of("ATL", "SFO"))));
    }

    // Time complexity: O(Elog(E/V)), space complexity: O(E + V)
    public static List<String> findItinerary(List<List<String>> tickets) {
        Map<String, Queue<String>> adjList = new HashMap<>();
        for (List<String> ticket : tickets) {
            adjList.computeIfAbsent(ticket.get(0), a -> new PriorityQueue<>()).offer(ticket.get(1));
        }
        LinkedList<String> res = new LinkedList<>();
        Deque<String> stack = new ArrayDeque<>();
        stack.push("JFK");
        while (!stack.isEmpty()) {
            String nextDest = stack.peek();
            if (!adjList.containsKey(nextDest) || adjList.get(nextDest).isEmpty()) {
                res.addFirst(stack.pop());
            } else {
                stack.push(adjList.get(nextDest).poll());
            }
        }
        return res;
    }
}
