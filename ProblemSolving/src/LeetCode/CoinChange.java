package LeetCode;


import java.util.Arrays;

public class CoinChange {

    public static void main(String[] args) {
        System.out.println(coinChange(new int[]{1, 2, 5}, 11));
        System.out.println(coinChange(new int[]{2}, 3));
        System.out.println(coinChange(new int[]{1}, 0));
        System.out.println(coinChange(new int[]{1, 2, 5}, 100));
        System.out.println(coinChange(new int[]{186,419,83,408}, 6249));
    }

    // Time Complexity: O(coins*amount), space complexity: O(amount)
    public static int coinChange(int[] coins, int amount) {
        int[] mem = new int[amount + 1];
        Arrays.fill(mem, amount + 1);
        mem[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    mem[i] = Math.min(mem[i], mem[i - coin] + 1);
                }
            }
        }
        return mem[amount] > amount ? -1 : mem[amount];
    }
}
