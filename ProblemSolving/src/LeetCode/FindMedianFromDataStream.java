package LeetCode;


import java.util.*;

public class FindMedianFromDataStream {

    public static void main(String[] args) {
        MedianFinder mf1 = new MedianFinder();
        mf1.addNum(1);
        mf1.addNum(2);
        System.out.println(mf1.findMedian());
        mf1.addNum(3);
        System.out.println(mf1.findMedian());
    }

    static class MedianFinder {

        private Queue<Integer> minHeap;
        private Queue<Integer> maxHeap;

        public MedianFinder() {
            minHeap = new PriorityQueue<>();
            maxHeap = new PriorityQueue<>((a,b)->b-a);
        }

        // Time Complexity: O(log(n)), space complexity: O(n)
        public void addNum(int num) {
            maxHeap.offer(num);
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.offer(maxHeap.poll());
            }
            if(!minHeap.isEmpty() && maxHeap.peek() > minHeap.peek()){
                minHeap.offer(maxHeap.poll());
                maxHeap.offer(minHeap.poll());
            }
        }

        // Time Complexity: O(1), space complexity: O(n)
        public double findMedian() {
            if((maxHeap.size() + minHeap.size()) % 2 == 1){
                return (double) maxHeap.peek();
            }else{
                return (double)(maxHeap.peek() + minHeap.peek()) / 2;
            }
        }
    }
}
