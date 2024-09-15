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
        // Step 1: Add to maxHeap
        maxHeap.push(num);

        // Step 2: Balance the heaps
        // Ensure every element in maxHeap is less than or equal to minHeap
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int tempMax = maxHeap.top();
            maxHeap.pop();
            int tempMin = minHeap.top();
            minHeap.pop();

            maxHeap.push(tempMin);
            minHeap.push(tempMax);
        }

        // Step 3: Maintain size property
        // The sizes of the heaps should not differ by more than 1
        if (maxHeap.size() > minHeap.size() + 1) {
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        } else if (minHeap.size() > maxHeap.size() + 1) {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
    }

    /** Returns the median of current data stream */
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // If even number of elements, median is the average of two middle values
            return ((double)maxHeap.top() + minHeap.top()) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            // If maxHeap has more elements
            return (double)maxHeap.top();
        } else {
            // If minHeap has more elements
            return (double)minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

