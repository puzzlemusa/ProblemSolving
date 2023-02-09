package LeetCode;


public class DecodeWays {

    public static void main(String[] args) {
//        System.out.println(numDecodings("12"));
//        System.out.println(numDecodings("226"));
//        System.out.println(numDecodings("06"));
//        System.out.println(numDecodings("30"));
//        System.out.println(numDecodings("31"));
//        System.out.println(numDecodings("031111"));
//        System.out.println(numDecodings("1"));
        System.out.println(numDecodings("102331"));
        System.out.println(numDecodings("1111"));
    }

    public static int numDecodings(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int n = s.length();
        int[] mem = new int[n + 1];
        mem[0] = 1;
        mem[1] = s.charAt(0) == '0' ? 0 : 1;

        for (int i = 2; i <= s.length(); i++) {
            int curr = s.charAt(i-1) - '0';
            int last2 = curr + ((s.charAt(i - 2) - '0') * 10);

            if (curr >= 1 && curr <= 9) {
                mem[i] += mem[i - 1];
            }
            if (last2 >= 10 && curr <= 26) {
                mem[i] += mem[i - 2];
            }
        }
        return mem[s.length()];
    }
}
