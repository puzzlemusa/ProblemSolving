package LeetCode;

public class CountAndSay {
    public static void main(String[] args) {
        System.out.println(countAndSay(1));
        System.out.println(countAndSay(2));
        System.out.println(countAndSay(3));
        System.out.println(countAndSay(4));
        System.out.println(countAndSay(5));
        System.out.println(countAndSay(6));
        System.out.println(countAndSay(7));
        System.out.println(countAndSay(30));
    }

    public static String countAndSay(int n) {
        if (n == 1)
            return "1";
        String count = countAndSay(n - 1);
        int freq = 1;
        String say = "";
        for (int i = 1; i < count.length(); i++) {
            if (count.charAt(i) == count.charAt(i - 1))
                freq++;
            else {
                say += String.valueOf(freq) + count.charAt(i - 1);
                freq = 1;
            }
        }
        say += String.valueOf(freq) + count.charAt(count.length() - 1);
        return say;
    }
}
