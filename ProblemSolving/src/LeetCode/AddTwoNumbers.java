package LeetCode;


public class AddTwoNumbers {

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
        ListNode one = new ListNode(9);
        ListNode two = new ListNode(9);
        ListNode three = new ListNode(9);
        ListNode four = new ListNode(9);
        ListNode five = new ListNode(9);
        ListNode six = new ListNode(9);

        five.next = six;
        four.next = five;
        two.next = three;
        one.next = two;

        System.out.println(addTwoNumbers(one, four));
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;

        ListNode temp = null;
        ListNode head = null;
        while (l1 != null || l2 != null) {
            int l1Val = 0;
            int l2Val = 0;
            if (l1 != null) {
                l1Val = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                l2Val = l2.val;
                l2 = l2.next;
            }
            ListNode newNode = new ListNode((l1Val + l2Val + carry) % 10);
            carry = (l1Val + l2Val + carry) / 10;

            if (temp != null) {
                temp.next = newNode;
                temp = temp.next;
            } else {
                temp = newNode;
                head = newNode;
            }
        }
        if (carry != 0) {
            ListNode msd = new ListNode(1);
            temp.next = msd;
        }
        return head;
    }
}
