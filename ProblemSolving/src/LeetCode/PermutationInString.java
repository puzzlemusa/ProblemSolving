package LeetCode;

public class PermutationInString {
    public static void main(String[] args) {
        System.out.println(checkInclusion("ab", "eidbaooo"));
        System.out.println(checkInclusion("ab", "eidboaoo"));
        System.out.println(checkInclusion("abc", "ecaidaboaobcao"));
        System.out.println(checkInclusion("abc", "ecaidaboaobcoao"));
        System.out.println(checkInclusion("hello", "ooolleoooleh"));
        System.out.println(checkInclusion("adc", "dcda"));

    }

    public static boolean checkInclusion(String s1, String s2) {
        int[] frequencies = new int[26];

        for (int i = 0; i < s1.length(); i++) {
            frequencies[s1.charAt(i) - 'a']++;
        }

        for (int i = 0; i < s2.length(); i++) {
            frequencies[s2.charAt(i) - 'a']--;
            if (i >= s1.length() - 1) {
                for (int j = 0; j < 26; j++) {
                    if (frequencies[j] != 0) {
                        break;
                    }
                    if (j == 25) {
                        return true;
                    }
                }
                frequencies[s2.charAt(i - (s1.length() - 1)) - 'a']++;
            }
        }

        return false;
    }
}
