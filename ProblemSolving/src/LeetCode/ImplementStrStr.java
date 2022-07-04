package LeetCode;

public class ImplementStrStr {
    public static void main(String[] args) {
        System.out.println(strStr("asdfsadfdssdf", "acabacacd"));
        System.out.println(strStr("hello", "ll"));
        System.out.println(strStr("aaaaa", "bba"));
    }

    public static int strStr(String haystack, String needle) {
        if (needle.length() == 0)
            return 0;
        int[] lps = makeLPS(needle);

        int i = 0;
        int j = 0;
        while (i < haystack.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            }
            if (j == needle.length())
                return i - j;
            if (i < haystack.length() && haystack.charAt(i) != needle.charAt(j)) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return 0-1;
    }

    public static int[] makeLPS(String needle) {
        int[] lps = new int[needle.length()];
        int p1 = 0;
        int p2 = 1;

        while (p2 < needle.length()) {
            if (needle.charAt(p2) == needle.charAt(p1)) {
                lps[p2++] = ++p1;
            } else if (p1 != 0)
                p1 = lps[p1 - 1];
            else
                lps[p2++] = 0;
        }
        return lps;
    }
}
