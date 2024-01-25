package LeetCode;


import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class MergeKSortedLists {

    public static void main(String[] args) {
        ListNode one = new ListNode(1);
        ListNode one1 = new ListNode(1);
        ListNode two = new ListNode(2);
        ListNode three = new ListNode(3);
        ListNode four = new ListNode(4);
        ListNode four1 = new ListNode(4);
        ListNode five = new ListNode(5);
        ListNode six = new ListNode(6);

        five.next = six;

        two.next = four;
        one.next = two;

        three.next = four1;
        one1.next = three;

        ListNode res = mergeKLists1(new ListNode[]{one, one1, five});
        while (res != null) {
            System.out.println(res.val);
            res = res.next;
        }
    }

    // Time complexity: O(nlog(k)), space complexity: O(k)
    public static ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a.val));
        for (ListNode list : lists) {
            if (list != null) {
                minHeap.add(list);
            }
        }
        ListNode start = new ListNode(0);
        ListNode temp = start;
        while (!minHeap.isEmpty()) {
            temp.next = minHeap.poll();
            temp = temp.next;
            if (temp.next != null) {
                minHeap.add(temp.next);
            }
        }

        return start.next;
    }

    // Time complexity: O(nlog(k)), space complexity: O(1)
    // 0 1 2 3 4 5 6 7 -> 01 1 23 3 45 5 67 7
    // 0123 1 23 3 4567 5 67 7
    // 01234567 1 23 34567 5 67 7
    public static ListNode mergeKLists1(ListNode[] lists) {
        int interval = 1;
        while (interval < lists.length) {
            for (int i = 0; i < lists.length - interval; i += 2 * interval) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists.length > 0 ? lists[0] : null;
    }

    public static ListNode merge(ListNode list1, ListNode list2) {
        ListNode start = new ListNode(0);
        ListNode curr = start;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        if (list1 != null) {
            curr.next = list1;
        }
        if (list2 != null) {
            curr.next = list2;
        }

        return start.next;
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
