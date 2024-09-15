#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    // Max-heap to store the smaller half elements
    priority_queue<int> maxHeap;

    // Min-heap to store the larger half elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    /** Initialize your data structure here. */
    MedianFinder() {}

    /** Adds a number into the data structure. */
    void addNum(int num) {
        // Add the number to maxHeap
        maxHeap.push(num);

        // Ensure that every number in maxHeap is less than or equal to every number in minHeap
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Balance the heaps if necessary (sizes must differ by at most 1)
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    /** Returns the median of current data stream */
    double findMedian() {
        // If the number of elements is odd, return the top of the heap with more elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } 
        // If the number of elements is even, return the average of the two middle elements
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
