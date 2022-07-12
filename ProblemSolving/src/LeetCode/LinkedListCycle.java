package LeetCode;


public class LinkedListCycle {

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
        ListNode three = new ListNode(3);
        ListNode four = new ListNode(4);
        ListNode five = new ListNode(5);

        four.next = five;
        three.next = two;
        two.next = three;
        one.next = two;

        System.out.println(hasCycle(one));
    }

    public static boolean hasCycle(ListNode head) {
        if (head == null)
            return false;
        ListNode slow = new ListNode(0);
        ListNode fast = new ListNode(0);
        slow.next = head;
        fast.next = head;

        while (fast != null && fast.next != null) {
            if (slow == fast)
                return true;
            slow = slow.next;
            fast = fast.next.next;
        }
        return false;
    }
}
