package LeetCode;


public class RemoveNthNodeFromEndOfList {

    public static void main(String[] args) {
        ListNode one = new ListNode(1);
        ListNode two = new ListNode(2);
        ListNode three = new ListNode(3);
        ListNode four = new ListNode(4);
        ListNode five = new ListNode(5);

        four.next = five;
        three.next = four;
        two.next = three;
        one.next = two;

        ListNode res = removeNthFromEnd(one, 4);
    }

    // Time complexity: O(n), space complexity: O(1)
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode start = new ListNode(0);
        ListNode slow = start;
        ListNode fast = start;
        slow.next = head;
        for (int i = 1; i <= n + 1; i++) {
            fast = fast.next;
        }

        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;

        return start.next;
    }

    // Time complexity: O(n), space complexity: O(1)
    public ListNode removeNthFromEnd1(ListNode head, int n) {
        if (head.next == null) {
            return null;
        }
        ListNode pointer = head;
        int total = 0;
        while (pointer != null) {
            pointer = pointer.next;
            total++;
        }

        if (total == n) {
            return head.next;
        }

        pointer = head;
        int counter = 1;
        while (counter < total - n) {
            pointer = pointer.next;
            counter++;
        }
        if (n == 1) {
            pointer.next = null;
        } else {
            pointer.next = pointer.next.next;
        }

        return head;
    }

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
}
