package LeetCode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LetterCombinationsOfAPhoneNumber {
    public static void main(String[] args) {
        System.out.println(letterCombinations("23"));
        System.out.println(letterCombinations(""));
        System.out.println(letterCombinations("1"));
        System.out.println(letterCombinations("12"));
        System.out.println(letterCombinations("21"));
        System.out.println(letterCombinations("213"));
        System.out.println(letterCombinations("283"));
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

        if(list1.isEmpty())
            return list2;

        if(list2.isEmpty())
            return list1;

        for (String str1 : list1) {
            for (String str2 : list2) {
                result.add(str1 + str2);
            }
        }

        return result;
    }
}
