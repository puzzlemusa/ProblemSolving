package LeetCode;


public class ReverseLinkedListII {

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

        ListNode result1 = reverseBetween(one, 3, 5);

        while (result1 != null) {
            System.out.println(result1.val);
            result1 = result1.next;
        }
    }

    // Time complexity: O(n), space complexity: O(1)
    public static ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) {
            return head;
        }

        int count = 1;
        ListNode start = head;
        ListNode temp = null;
        while (count < left) {
            temp = start;
            start = start.next;
            count++;
        }

        ListNode tempStart = start;
        ListNode prev = null;
        while (count <= right) {
            ListNode next = start.next;
            start.next = prev;
            prev = start;
            start = next;
            count++;
        }
        if(temp != null){
            temp.next = prev;
        }
        tempStart.next = start;

        return left==1 ? prev : head;
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
