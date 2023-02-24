package LeetCode;

import java.util.HashMap;
import java.util.Map;

public class LRUCache {

    public class Node {
        int key;
        int val;
        Node next;
        Node previous;

        Node() {
        }

        Node(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }

    private int limit;
    private Map<Integer, Node> keyToNode;
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        keyToNode = new HashMap<>();
        limit = capacity;
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.previous = head;
    }

    public int get(int key) {
        if (keyToNode.containsKey(key)) {
            Node node = keyToNode.get(key);
            removeNode(node);
            addToHead(node);
            return node.val;
        } else {
            return -1;
        }
    }

    public void put(int key, int value) {
        Node node;
        if (keyToNode.containsKey(key)) {
            node = keyToNode.get(key);
            removeNode(node);
            node.val = value;
        } else {
            node = new Node(key, value);
            if (keyToNode.size() == limit) {
                keyToNode.remove(tail.previous.key);
                removeNode(tail.previous);
            }
        }
        addToHead(node);
        keyToNode.put(key, node);
    }

    private void addToHead(Node node) {
        node.next = head.next;
        node.previous = head;
        head.next.previous = node;
        head.next = node;
    }

    private void removeNode(Node node) {
        node.previous.next = node.next;
        node.next.previous = node.previous;
    }
}
