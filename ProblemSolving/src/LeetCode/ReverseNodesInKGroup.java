package LeetCode;


public class ReverseNodesInKGroup {

    public static void main(String[] args) {
        ListNode one = new ListNode(1);
        ListNode two = new ListNode(2);
        ListNode three = new ListNode(3);
        ListNode four = new ListNode(4);
        ListNode five = new ListNode(5);
        ListNode six = new ListNode(6);

        five.next = six;
        four.next = five;
        three.next = four;
        two.next = three;
        one.next = two;

        ListNode res = reverseKGroup(one, 2);
        while (res != null) {
            System.out.println(res.val);
            res = res.next;
        }
    }

    // Time complexity: O(n), space complexity: O(n)
    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode curr = head;
        int count = 0;
        while (curr != null && count != k) {
            curr = curr.next;
            count++;
        }
        if (count == k) {
            curr = reverseKGroup(curr, k);
            while (count-- > 0) {
                ListNode next = head.next;
                head.next = curr;
                curr = head;
                head = next;
            }
            head = curr;
        }
        return head;
    }

    private static ListNode reverse(ListNode head, ListNode prev, int n) {
        if (head == null || n == 0) {
            return prev;
        }
        ListNode next = head.next;
        head.next = prev;
        return reverse(next, head, n - 1);
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
