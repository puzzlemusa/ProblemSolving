package LeetCode;


public class SentenceReverse {
    public static void main(String[] args) {
        System.out.println(reverseWords1(new char[]{' ', ' '}));
        System.out.println(reverseWords1(new char[]{'a', ' ', ' ', 'b'}));
        System.out.println(reverseWords1(new char[]{'p', 'e', ' ', 'm', 'a', ' ', 'p', 'r'}));
        System.out.println(reverseWords1(new char[]{'p', 'e', 'r', 'f', 'e', 'c', 't', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'}));
    }

    // https://www.pramp.com/challenge/VKdqbrq6B1S5XAyGAOn4
    static char[] reverseWords(char[] arr) {
        char[] res = new char[arr.length];

        int left = 0;
        int right = 0;
        while (left < arr.length) {
            while (right < arr.length && arr[right] != ' ') {
                right++;
            }
            if (right < arr.length && arr[right] != ' ') {
                res[arr.length - 1 - right] = ' ';
            }
            for (int i = arr.length - right; left < right; i++) {
                res[i] = arr[left++];
            }
            right++;
            left = right;
        }

        return res;
    }

    // Time complexity: O(n), space complexity: O(1)
    public static char[] reverseWords1(char[] arr) {
        int n = arr.length;
        mirrorReverse(arr, 0, n - 1);

        Integer wordStart = null;
        for (int i = 0; i < n; i++) {
            if (arr[i] == ' ') {
                if (wordStart != null) {
                    mirrorReverse(arr, wordStart, i - 1);
                    wordStart = null;
                }
            } else if (i == n - 1) {
                if (wordStart != null) {
                    mirrorReverse(arr, wordStart, i);
                }
            } else {
                if (wordStart == null) {
                    wordStart = i;
                }
            }
        }

        return arr;
    }

    private static void mirrorReverse(char[] arr, int start, int end) {
        char tmp;
        while (start < end) {
            tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            start++;
            end--;
        }
    }
}
