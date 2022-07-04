package LeetCode;

public class LongestCommonPrefix {
    public static void main(String[] args) {
        System.out.println(longestCommonPrefix(new String[]{"flower", "flow", "flight"}));
        System.out.println(longestCommonPrefix(new String[]{"dog","racecar","car"}));
        System.out.println(longestCommonPrefix(new String[]{"flower", "", "flight"}));
        System.out.println(longestCommonPrefix(new String[]{"flower", "flower", "flower"}));
        System.out.println(longestCommonPrefix(new String[]{"flower"}));
    }

    public static String longestCommonPrefix(String[] strs) {
        int j = 0;
        String res = "";
        char ch = 0;
        boolean end = false;
        while (true) {
            for (int i = 0; i < strs.length; i++) {
                if (j == strs[i].length()) {
                    end = true;
                    break;
                }


                if (i == 0)
                    ch = strs[i].charAt(j);
                else if (ch != strs[i].charAt(j)) {
                    end = true;
                    break;
                }
            }
            if (end)
                break;
            res += ch;
            j++;
        }
        return res;
    }
}
