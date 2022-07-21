package LeetCode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GroupAnagrams {
    public static void main(String[] args) {
        System.out.println(groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"}));
    }

    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramToItsListMap = new HashMap<>();

        for (String str : strs) {
            char[] charUsage = new char[26];

            for (char c : str.toCharArray())
                charUsage[c - 'a']++;
            String anagram = String.valueOf(charUsage);
            List<String> anagrams = anagramToItsListMap.get(anagram);
            if (anagrams == null) {
                anagrams = new ArrayList<>();
            }
            anagrams.add(str);
            anagramToItsListMap.put(anagram, anagrams);
        }

        return new ArrayList<>(anagramToItsListMap.values());
    }
}
