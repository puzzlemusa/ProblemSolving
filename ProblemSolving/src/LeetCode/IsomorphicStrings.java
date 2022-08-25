package LeetCode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class IsomorphicStrings {
    public static void main(String[] args) {
        System.out.println(isIsomorphic("egg", "add"));
        System.out.println(isIsomorphic("foo", "bar"));
        System.out.println(isIsomorphic("paper", "title"));
        System.out.println(isIsomorphic("badc", "baba"));
        System.out.println("----------------------------");
        System.out.println(isIsomorphic1("egg", "add"));
        System.out.println(isIsomorphic1("foo", "bar"));
        System.out.println(isIsomorphic1("paper", "title"));
        System.out.println(isIsomorphic1("badc", "baba"));
    }

    public static boolean isIsomorphic1(String s, String t) {
        int[] StoT = new int[256];
        Arrays.fill(StoT, -1);

        int[] TtoS = new int[256];
        Arrays.fill(TtoS, -1);

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);

            if (StoT[c1] == -1 && TtoS[c2] == -1) {
                StoT[c1] = c2;
                TtoS[c2] = c1;
            }

            else if (!(StoT[c1] == c2 && TtoS[c2] == c1)) {
                return false;
            }
        }

        return true;
    }

    private static String transformString(String s) {
        Map<Character, Integer> indexMapping = new HashMap<>();
        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s.charAt(i);

            if (!indexMapping.containsKey(c1)) {
                indexMapping.put(c1, i);
            }

            builder.append(Integer.toString(indexMapping.get(c1)));
            builder.append(" ");
        }
        return builder.toString();
    }

    public static boolean isIsomorphic(String s, String t) {
        return transformString(s).equals(transformString(t));
    }
}
