package LeetCode;


import java.util.*;

public class CheapestFlightsWithinKStops {

    public static void main(String[] args) {
        System.out.println(new CheapestFlightsWithinKStops().findCheapestPrice(3, new int[][]{
                new int[]{0, 1, 100},
                new int[]{1, 2, 100},
                new int[]{2, 0, 100},
                new int[]{1, 3, 600}
        }, 0, 3, 1));

        System.out.println(new CheapestFlightsWithinKStops().findCheapestPrice(3, new int[][]{
                new int[]{0, 1, 100},
                new int[]{1, 2, 100},
                new int[]{0, 2, 500},
        }, 0, 2, 1));

        System.out.println(new CheapestFlightsWithinKStops().findCheapestPrice(3, new int[][]{
                new int[]{0, 1, 100},
                new int[]{1, 2, 100},
                new int[]{0, 2, 500},
        }, 0, 2, 0));
    }

    // Time complexity: O(V^2*(K+1)), Space complexity: O(V + E)
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Map<Integer, List<int[]>> adjs = new HashMap<>();
        for (int[] flight : flights) {
            adjs.putIfAbsent(flight[0], new ArrayList<>());
            adjs.get(flight[0]).add(new int[]{flight[1], flight[2]});
        }

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{src, 0});

        int cost = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int[] node = q.poll();
                if (node[0] == dst) {
                    cost = Math.min(cost, node[1]);
                }
                if (!adjs.containsKey(node[0])) {
                    continue;
                }
                for (int[] adj : adjs.get(node[0])) {
                    if (node[1] + adj[1] > cost) {
                        continue;
                    }
                    q.offer(new int[]{adj[0], node[1] + adj[1]});
                }
            }
            if (k-- < 0) {
                break;
            }
        }

        return cost == Integer.MAX_VALUE ? -1 : cost;
    }
}
