package LeetCode;


public class ReverseLinkedList {

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

        three.next = four;
        two.next = three;
        one.next = two;

        //ListNode result = reverseList(one);
        ListNode result1 = reverseListRecursive(one);

        System.out.println("asdf");
    }

    public static ListNode reverseList(ListNode head) {
        ListNode result = null;
        ListNode next = null;
        while (head != null) {
            next = head.next;
            head.next = result;
            result = head;
            head = next;
        }

        return result;
    }

    public static ListNode reverseListRecursive(ListNode head) {
        return reverse(head, null);
    }

    private static ListNode reverse(ListNode head, ListNode newNode) {
        if (head == null)
            return newNode;
        ListNode next = head.next;
        head.next = newNode;
        return reverse(next, head);
    }
}
