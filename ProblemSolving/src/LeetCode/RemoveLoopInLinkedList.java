package LeetCode;


import java.util.HashSet;
import java.util.Set;

public class RemoveLoopInLinkedList {

    public static void main(String[] args) {
        ListNode one = new ListNode(1);
        ListNode two = new ListNode(2);
        ListNode three = new ListNode(3);
        ListNode four = new ListNode(4);
        ListNode five = new ListNode(5);

        five.next = two;
        four.next = five;
        three.next = four;
        two.next = three;
        one.next = two;

        System.out.println(removeLoop1(one));
        ListNode res = one;
        while (res != null) {
            System.out.println(res.val);
            res = res.next;
        }
    }

    // Time complexity: O(n), space complexity: O(n)
    public static boolean removeLoop(ListNode head) {
        Set<Integer> uniqueNode = new HashSet<>();
        ListNode prev = null;
        while (head != null) {
            if (uniqueNode.contains(head.val)) {
                prev.next = null;
                return true;
            } else {
                uniqueNode.add(head.val);
                prev = head;
                head = head.next;
            }
        }

        return false;
    }

    // Time complexity: O(n), space complexity: O(1)
    public static boolean removeLoop1(ListNode head) {
        ListNode ptr1 = detectCycle(head);
        ListNode ptr2 = head;
        ListNode prev = null;
        while (true) {
            prev = ptr1;
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
            if (ptr1 == ptr2) {
                prev.next = null;
                return true;
            }
        }
    }

    private static ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return slow;
            }
        }

        return null;
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
