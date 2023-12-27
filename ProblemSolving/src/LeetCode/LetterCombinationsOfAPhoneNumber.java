package LeetCode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

public class LetterCombinationsOfAPhoneNumber {
    private static Map<Character, String> digitToChar = Map.of(
            '2',
            "abc",
            '3',
            "def",
            '4',
            "ghi",
            '5',
            "jkl",
            '6',
            "mno",
            '7',
            "pqrs",
            '8',
            "tuv",
            '9',
            "wxyz"
    );

    public static void main(String[] args) {
        System.out.println(letterCombinations("23"));
        System.out.println(letterCombinations(""));
        System.out.println(letterCombinations("1"));
        System.out.println(letterCombinations("12"));
        System.out.println(letterCombinations("21"));
        System.out.println(letterCombinations("213"));
        System.out.println(letterCombinations("283"));
        System.out.println(letterCombinations1("283"));
    }

    public static List<String> letterCombinations(String digits) {
        List<List<String>> buttons = new ArrayList<>();
        buttons.add(List.of());
        buttons.add(List.of());
        buttons.add(Arrays.asList("a", "b", "c"));
        buttons.add(Arrays.asList("d", "e", "f"));
        buttons.add(Arrays.asList("g", "h", "i"));
        buttons.add(Arrays.asList("j", "k", "l"));
        buttons.add(Arrays.asList("m", "n", "o"));
        buttons.add(Arrays.asList("p", "q", "r", "s"));
        buttons.add(Arrays.asList("t", "u", "v"));
        buttons.add(Arrays.asList("w", "x", "y", "z"));

        List<String> result = new ArrayList();

        if (digits == null || digits == "")
            return result;

        if (digits.length() == 1)
            return buttons.get(digits.charAt(0) - '0');

        for (int i = 0; i < digits.length(); i++) {
            result = combine(result, buttons.get((digits.charAt(i) - '0')));
        }

        return result;
    }

    public static List<String> combine(List<String> list1, List<String> list2) {
        List<String> result = new ArrayList();

        if (list1.isEmpty())
            return list2;

        if (list2.isEmpty())
            return list1;

        for (String str1 : list1) {
            for (String str2 : list2) {
                result.add(str1 + str2);
            }
        }

        return result;
    }

    // Time complexity: O(4^n), Space complexity: O(n)
    public static List<String> letterCombinations1(String digits) {
        if (digits.length() == 0) {
            return new ArrayList();
        }

        List<String> ans = new ArrayList();
        String cur = "";
        backtrack(digits, ans, cur, 0);
        return ans;
    }

    public static void backtrack(String digits, List<String> ans, String cur, int index) {
        if (cur.length() == digits.length()) {
            ans.add(cur);
        } else if (index >= digits.length()) {
        } else {
            String letters = digitToChar.get(digits.charAt(index));
            for (int i = 0; i < letters.length(); i++) {
                backtrack(digits, ans, cur + letters.charAt(i), index + 1);
            }
        }
    }
}
