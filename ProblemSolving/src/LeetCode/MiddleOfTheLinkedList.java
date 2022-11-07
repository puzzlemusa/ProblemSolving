package LeetCode;


public class MiddleOfTheLinkedList {

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

        ListNode result = middleNode(one);

        System.out.println("asdf");
    }

    public static ListNode middleNode(ListNode head) {
        int i=1;
        ListNode sP = new ListNode(0);
        sP.next = head;
        ListNode fP = head;

        while(fP != null){
            fP = fP.next;
            if(i%2==0)
                sP = sP.next;
            i++;
        }

        return sP.next;
    }
}
