package LeetCode;


import java.util.*;

public class TopKFrequentElements {

    static Map<Integer, Integer> mp;
    static int[] unique;

    public static void main(String[] args) {
        System.out.println(Arrays.toString(topKFrequent(new int[]{1, 1, 1, 2, 2, 3}, 2)));
        System.out.println(Arrays.toString(topKFrequent(new int[]{1}, 1)));

        System.out.println(Arrays.toString(topKFrequentLonN(new int[]{3, 0, 1, 0}, 1)));
        System.out.println(Arrays.toString(topKFrequentLonN(new int[]{1, 1, 1, 2, 2, 3}, 2)));
        System.out.println(Arrays.toString(topKFrequentLonN(new int[]{1}, 1)));
    }

    // Complexity nLog(k)
    public static int[] topKFrequent(int[] nums, int k) {
        mp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        Queue<Integer> q = new PriorityQueue<>((i1, i2) -> {
            return mp.get(i1) - mp.get(i2);
        });

        for (int n : mp.keySet()) {
            q.add(n);
            if (q.size() > k) {
                q.poll();
            }
        }

        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = q.poll();
        }

        return res;
    }

    // AVG Complexity log(n), WORST Complexity n^2
    public static int[] topKFrequentLonN(int[] nums, int k) {
        mp = new HashMap<>();

        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        int n = mp.size();
        unique = new int[n];
        int i = 0;
        for (int key : mp.keySet()) {
            unique[i] = key;
            i++;
        }

        quickSelect(0, n - 1, n - k);

        return Arrays.copyOfRange(unique, n - k, n);
    }

    private static void quickSelect(int left, int right, int k) {
        if (left == right)
            return;

        int pivotIndex = partition(left, right);
        if (pivotIndex == k) {
            return;
        } else if (pivotIndex < k) {
            quickSelect(pivotIndex + 1, right, k);
        } else {
            quickSelect(left, pivotIndex - 1, k);
        }
    }

    private static int partition(int left, int right) {
        int pivotFrequency = mp.get(unique[right]);
        int storeIndex = left;

        for (int i = left; i <= right; i++) {
            if (mp.get(unique[i]) < pivotFrequency) {
                swap(storeIndex, i);
                storeIndex++;
            }
        }

        swap(storeIndex, right);

        return storeIndex;
    }

    private static void swap(int i, int j) {
        int temp = unique[i];
        unique[i] = unique[j];
        unique[j] = temp;
    }
}
