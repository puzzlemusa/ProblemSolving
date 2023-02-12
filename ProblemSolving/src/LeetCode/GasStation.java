package LeetCode;


public class GasStation {
    public static void main(String[] args) {
        System.out.println(canCompleteCircuit(new int[]{1, 2, 3, 4, 5}, new int[]{3, 4, 5, 1, 2}));
        System.out.println(canCompleteCircuit(new int[]{2, 3, 4}, new int[]{3, 4, 3}));
        System.out.println(canCompleteCircuit(new int[]{4, 5, 2, 6, 5, 3}, new int[]{3, 2, 7, 3, 2, 9}));
    }

    public static int canCompleteCircuit(int[] gas, int[] cost) {
        int tank = 0;
        int totDiff = 0;
        int start = 0;
        for (int i = 0; i < gas.length; i++) {
            tank += gas[i] - cost[i];
            totDiff += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }

        return totDiff < 0 ? -1 : start;
    }
}
