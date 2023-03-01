package LeetCode;

public class MinStack {

    public class Node {
        int val;
        int min;
        Node next;

        Node() {
        }

        Node(int val, int min) {
            this.val = val;
            this.min = min;
        }
    }

    private Node head;

    public MinStack() {
        head = new Node();
    }

    public void push(int val) {
        if (head.next == null) {
            head.next = new Node(val, val);
        } else {
            Node node = new Node(val, Math.min(val, head.next.min));
            node.next = head.next;
            head.next = node;
        }
    }

    public void pop() {
        head = head.next;
    }

    public int top() {
        return head.next.val;
    }

    public int getMin() {
        return head.next.min;
    }
}
