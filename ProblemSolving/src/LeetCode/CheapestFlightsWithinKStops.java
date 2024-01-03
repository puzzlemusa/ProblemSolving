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

    // Time Complexity O(k * n) | Space Complexity O(n)
    public static int findCheapestPrice1(int n, int[][] flights, int src, int dst, int k
    ) {
        int[] prices = new int[n];
        Arrays.fill(prices, Integer.MAX_VALUE);

        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            // make a copy of prices
            int[] temp = new int[n];
            temp = Arrays.copyOf(prices, prices.length);

            // loop through flights
            for (int j = 0; j < flights.length; j++) {
                int s = flights[j][0]; // from
                int d = flights[j][1]; // to
                int p = flights[j][2]; // price

                if (prices[s] == Integer.MAX_VALUE) {
                    continue;
                }

                if (prices[s] + p < temp[d]) {
                    temp[d] = prices[s] + p;
                }
            }

            // set prices to temp
            prices = temp;
        }

        if (prices[dst] != Integer.MAX_VALUE) {
            return prices[dst];
        }

        return -1;
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
