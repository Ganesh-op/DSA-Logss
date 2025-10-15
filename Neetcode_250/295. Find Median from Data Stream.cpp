class MedianFinder {
public:

    // The median of an array occurs at the center of sorted array, so the idea is to store the current elements in two nearly equal parts. A max heap (left half) stores the smaller elements, ensuring the largest among them is at the top, while a min heap (right half) stores the larger elements, keeping the smallest at the top.

    // For each new element:
    // - It is first added to the max heap.
    // - The max heap's top element is moved to the min heap to maintain order.
    // - If the min heap has more elements than the max heap, its top element is moved back to ensure balance.

    // This keeps both halves nearly equal in size, differing by at most one element. If the heaps are balanced, the median is the average of their root values; otherwise, it is the root of the heap with more elements.

    // Time Complexity: O(n * log n), SC = O(n)

   priority_queue<int> leftMaxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; // larger half

    MedianFinder() {}
    
    void addNum(int num) {
        // Step 1: Always push into left heap first
        if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            rightMinHeap.push(num);
        }

        // Step 2: Balance both heaps (size difference should be at most 1)
        if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } else if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if (leftMaxHeap.size() == rightMinHeap.size()) {
            return ((double)leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        } 
        return leftMaxHeap.top(); // left will always have 1 extra if odd
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */