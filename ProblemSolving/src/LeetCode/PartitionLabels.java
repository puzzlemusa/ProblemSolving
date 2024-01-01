package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class PartitionLabels {

    public static void main(String[] args) {
        System.out.println(partitionLabels("ababcbacadefegdehijhklij"));
        System.out.println(partitionLabels("eccbbbbdec"));
        System.out.println(partitionLabels("a"));
        System.out.println(partitionLabels("ab"));
        System.out.println(partitionLabels("ba"));
        System.out.println(partitionLabels("aa"));
    }

    // Time: O(n), Space: O(n)
    public static List<Integer> partitionLabels(String s) {
        int[] lastSeen = new int[26];
        for (int i = s.length() - 1; i >= 0; i--) {
            if (lastSeen[s.charAt(i) - 'a'] == 0) {
                lastSeen[s.charAt(i) - 'a'] = i;
            }
        }

        List<Integer> res = new ArrayList<>();
        int partitionStart = 0;
        int left = 0;
        while (left < s.length()) {
            int right = lastSeen[s.charAt(left) - 'a'];
            while (left < right) {
                right = Math.max(right, lastSeen[s.charAt(left) - 'a']);
                left++;
            }
            res.add(right - partitionStart + 1);
            left = partitionStart = left + 1;
        }

        return res;
    }
}
