package LeetCode;

public class ValidAnagram {
    public static void main(String[] args) {
        System.out.println(isAnagram("anagram", "nagaram"));
        //System.out.println(isAnagram("rat", "cat"));
        //System.out.println(isAnagram("aa", "a"));
    }

    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;

        int[] chars = new int[26];
        for (int i = 0; i < s.length(); i++) {
            int ids = s.charAt(i) - 'a';
            int idt = t.charAt(i) - 'a';
            chars[ids]++;
            chars[idt]--;
        }

        for (int i = 0; i < chars.length; i++) {
            if (chars[i] != 0)
                return false;
        }

        return true;
    }
}
