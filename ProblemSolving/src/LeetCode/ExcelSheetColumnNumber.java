package LeetCode;


public class ExcelSheetColumnNumber {

    public static void main(String[] args) {
        System.out.println(titleToNumber("A"));
        System.out.println(titleToNumber("AB"));
        System.out.println(titleToNumber("ZY"));
    }

    public static int titleToNumber(String columnTitle) {
        int res = 0;
        for (int i = 0; i < columnTitle.length(); i++) {
            res += Math.pow(26, columnTitle.length() - i - 1) * (columnTitle.charAt(i) - 'A' + 1);
        }

        return res;
    }
}
