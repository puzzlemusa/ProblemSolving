package LeetCode;

public class LongestRepeatingCharacterReplacement {
    public static void main(String[] args) {
        System.out.println(characterReplacement("ABAB", 2));
        System.out.println(characterReplacement("AABABBA", 1));

    }

    public static int characterReplacement(String s, int k) {
        int[] frequencies = new int[26];
        int maxFrequency = 0;
        int res = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            frequencies[s.charAt(right) - 'A']++;
            maxFrequency = Math.max(maxFrequency, frequencies[s.charAt(right) - 'A']);
            if (right - left + 1 - maxFrequency > k) {
                frequencies[s.charAt(left) - 'A']--;
                left++;
            }
            res = Math.max(res, right - left + 1);
        }

        return res;
    }
}
