package LeetCode;


public class ReorderList {

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
        ListNode six = new ListNode(6);

        //five.next = six;
        four.next = five;
        three.next = four;
        two.next = three;
        one.next = two;

        reorderList(one);
        while (one != null){
            System.out.println(one.val);
            one = one.next;
        }
    }

    // Time complexity: O(n), space complexity: O(n)
    public static void reorderList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow.next = reverse(slow.next, null);
        ListNode p1 = head;
        ListNode p2 = slow.next;
        slow.next=null;
        while(p2 != null) {
            ListNode temp = p2.next;
            p2.next = p1.next;
            p1.next = p2;
            p1 = p2.next;
            p2 = temp;
        }
    }

    private static ListNode reverse(ListNode head, ListNode prevNode) {
        if (head == null)
            return prevNode;
        ListNode next = head.next;
        head.next = prevNode;
        return reverse(next, head);
    }
}
