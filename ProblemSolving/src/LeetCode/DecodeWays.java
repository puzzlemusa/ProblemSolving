package LeetCode;


public class DecodeWays {

    public static void main(String[] args) {
        System.out.println(numDecodings1("11106"));
        System.out.println(numDecodings1("12"));
        System.out.println(numDecodings1("226"));
        System.out.println(numDecodings1("06"));
        System.out.println(numDecodings1("27"));
        System.out.println(numDecodings("30"));
        System.out.println(numDecodings("31"));
        System.out.println(numDecodings("031111"));
        System.out.println(numDecodings("1"));
        System.out.println(numDecodings("102331"));
        System.out.println(numDecodings("1111"));
        System.out.println(numDecodings("10"));
    }

    // Time Complexity: O(n), space complexity: O(n)
    public static int numDecodings(String s) {
        int n = s.length();
        int[] mem = new int[n + 1];
        mem[0] = 1;
        mem[1] = s.charAt(0) == '0' ? 0 : 1;

        for (int i = 2; i <= s.length(); i++) {
            int curr = s.charAt(i - 1) - '0';
            int last2 = curr + ((s.charAt(i - 2) - '0') * 10);

            if (curr != 0) {
                mem[i] = mem[i - 1];
            }

            if (last2 >= 10 && last2 <= 26) {
                mem[i] += mem[i - 2];
            }
        }
        return mem[s.length()];
    }

    // Time Complexity: O(n), space complexity: O(1)
    public static int numDecodings1(String s) {
        int dp1 = 1;
        int dp2 = s.charAt(0) == '0' ? 0 : 1;

        for (int i = 2; i <= s.length(); i++) {
            int curr = s.charAt(i - 1) - '0';
            int last2 = curr + ((s.charAt(i - 2) - '0') * 10);
            int temp = 0;
            if (curr != 0) {
                temp = dp2;
            }

            if (last2 >= 10 && last2 <= 26) {
                temp += dp1;
            }
            dp1 = dp2;
            dp2 = temp;
        }
        return dp2;
    }
}
