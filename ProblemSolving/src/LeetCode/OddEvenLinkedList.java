package LeetCode;


public class OddEvenLinkedList {

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

        five.next = six;
        four.next = five;
        three.next = four;
        two.next = three;
        one.next = two;

        System.out.println(oddEvenList(one));
    }

    public static ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode lastOdd = head;
        ListNode firstEven = head.next;
        ListNode lastEven = head.next;

        while (lastEven != null) {
            ListNode nextOddPointer = lastEven.next;

            if(nextOddPointer == null)
                return head;

            lastEven.next = nextOddPointer.next;
            lastOdd.next = nextOddPointer;
            nextOddPointer.next = firstEven;

            lastOdd = lastOdd.next;
            lastEven = lastEven.next;
        }

        return head;
    }
}
