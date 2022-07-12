package LeetCode;


public class PalindromeLinkedList {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public static void main(String[] args) {
        ListNode one = new ListNode(1);
        ListNode two = new ListNode(2);
        ListNode three = new ListNode(2);
        ListNode four = new ListNode(1);
        ListNode five = new ListNode(1);

        //four.next = five;
        three.next = four;
        two.next = three;
        one.next = two;

        System.out.println(isPalindrome(one));
    }

    public static boolean isPalindrome(ListNode head) {
        ListNode slow = new ListNode(0);
        ListNode fast = new ListNode(0);
        slow.next = head;
        fast.next = head;
        fast = fast.next;
        int i = 0;
        while (fast != null) {
            if (i % 2 == 1)
                slow = slow.next;
            i++;
            fast = fast.next;
        }
        if (i == 0)
            return true;

        slow = slow.next;
        if (i % 2 == 1)
            slow = slow.next;
        ListNode reversed = getReversed(slow);
        while (reversed != null) {
            if (head.val != reversed.val)
                return false;
            head = head.next;
            reversed = reversed.next;
        }

        return true;
    }

    public static ListNode getReversed(ListNode head) {
        ListNode result = null;
        ListNode temp = null;

        while (head != null) {
            temp = head.next;
            head.next = result;
            result = head;
            head = temp;
        }

        return result;
    }
}
