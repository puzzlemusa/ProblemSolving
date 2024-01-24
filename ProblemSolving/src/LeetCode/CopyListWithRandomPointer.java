package LeetCode;


import java.util.HashMap;
import java.util.Map;

public class CopyListWithRandomPointer {

    public static void main(String[] args) {
        Node one = new Node(1);
        Node two = new Node(2);
        Node three = new Node(3);
        Node four = new Node(4);
        Node five = new Node(5);

        four.next = five;
        three.next = four;
        two.next = three;
        one.next = two;

        one.random = five;
        two.random = four;
        three.random = null;
        four.random = two;
        five.random = one;

        Node res = copyRandomList(one);
    }

    // Time complexity: O(n), space complexity: O(n)
    public static Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Map<Node, Integer> mainMap = new HashMap<>();
        Map<Integer, Node> copyMap = new HashMap<>();
        Node start = new Node(0);
        Node prev = new Node(0);
        Node headPointer = head;
        start.next = prev;
        int index = 0;
        while (headPointer != null) {
            Node newNode = new Node(headPointer.val);
            mainMap.put(headPointer, index);
            copyMap.put(index, newNode);
            prev.next = newNode;
            prev = prev.next;
            headPointer = headPointer.next;
            index++;
        }
        Node copyPointer = start.next.next;
        start = new Node(0);
        start.next = copyPointer;
        while (head != null) {
            if (head.random == null) {
                copyPointer.random = null;
            } else {
                int randomIndex = mainMap.get(head.random);
                copyPointer.random = copyMap.get(randomIndex);
            }
            head = head.next;
            copyPointer = copyPointer.next;
        }

        return start.next;
    }

    // Time complexity O(n), Space complexity: O(1)
    public static Node copyRandomList2(Node head) {
        Node iter = head, next;

        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (iter != null) {
            next = iter.next;

            Node copy = new Node(iter.val);
            iter.next = copy;
            copy.next = next;

            iter = next;
        }

        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter != null) {
            if (iter.random != null) {
                iter.next.random = iter.random.next;
            }
            iter = iter.next.next;
        }

        // Third round: restore the original list, and extract the copy list.
        iter = head;
        Node pseudoHead = new Node(0);
        Node copy, copyIter = pseudoHead;

        while (iter != null) {
            next = iter.next.next;

            // extract the copy
            copy = iter.next;
            copyIter.next = copy;
            copyIter = copy;

            // restore the original list
            iter.next = next;

            iter = next;
        }

        return pseudoHead.next;
    }

    // Time complexity: O(n), space complexity: O(n)
    public Node copyRandomList1(Node head) {
        if (head == null) return null;

        Map<Node, Node> map = new HashMap<>();

        Node node = head;
        while (node != null) {
            map.put(node, new Node(node.val));
            node = node.next;
        }

        node = head;
        while (node != null) {
            map.get(node).next = map.get(node.next);
            map.get(node).random = map.get(node.random);
            node = node.next;
        }

        return map.get(head);
    }

    static class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }
}
