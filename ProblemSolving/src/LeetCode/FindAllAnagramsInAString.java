package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class FindAllAnagramsInAString {

    public static void main(String[] args) {
        System.out.println(findAnagrams("cbaebabacd", "abc"));
        System.out.println(findAnagrams("abab", "ab"));
    }

    public static List<Integer> findAnagrams(String s, String p) {
        int[] holder = new int[26];
        for (int i = 0; i < p.length(); i++) {
            holder[p.charAt(i) - 'a']++;
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            holder[s.charAt(i) - 'a']--;

            if (i >= p.length() - 1) {
                int j = 0;
                for (j = 0; j < 26; j++) {
                    if (holder[j] != 0) {
                        break;
                    }
                }
                if (j == 26) {
                    result.add(i - p.length() + 1);
                }

                holder[s.charAt(i - p.length() + 1) - 'a']++;
            }
        }

        return result;
    }
}
