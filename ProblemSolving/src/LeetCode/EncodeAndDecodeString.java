package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class EncodeAndDecodeString {

    public static void main(String[] args) {
        System.out.println(encode(List.of("Hello", "World", "Java", "Programming")) + "->" + decode(encode(List.of("Hello", "World", "Java", "Programming"))));
    }

    // Time complexity: O(n), Space complexity: O(n)
    public static String encode(List<String> strs) {
        StringBuilder encodedString = new StringBuilder();

        for (String str : strs) {
            encodedString.append((char) str.length()).append(str);
        }

        return encodedString.toString();
    }

    // Time complexity: O(n), Space complexity: O(n)
    public static List<String> decode(String s) {
        List<String> decodedStrings = new ArrayList<>();

        int index = 0;
        int length = s.length();

        while (index < length) {
            int size = s.charAt(index++);
            decodedStrings.add(s.substring(index, index + size));
            index += size;
        }

        return decodedStrings;
    }
}
