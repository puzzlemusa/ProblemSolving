package LeetCode;

import java.util.Map;
import java.util.Set;

public class CountPrefixAndSuffixPairsI {

    public static void main(String[] args) {
        System.out.println(countPrefixSuffixPairs(new String[]{"a","aba","ababa","aa"}));
        System.out.println(countPrefixSuffixPairs(new String[]{"pa","papa","ma","mama"}));
        System.out.println(countPrefixSuffixPairs(new String[]{"abab","ab"}));
    }

    // Time complexity O(n^2), space complexity O(1)
    public static int countPrefixSuffixPairs(String[] words) {
        int result = 0;
        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    result++;
                }

            }
        }
        return result;
    }

    private static boolean isPrefixAndSuffix(String str1, String str2) {
        return str2.startsWith(str1) && str2.endsWith(str1);
    }
}
