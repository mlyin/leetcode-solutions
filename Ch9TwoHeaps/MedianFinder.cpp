#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class MedianFinder {
public:
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        maxHeap = priority_queue<int>(); //bottom of list
        priority_queue<int, vector<int>, greater<int>> pq;	
        minHeap = pq; //top of list
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() >= num) {
        	maxHeap.push(num);
        } else {
        	minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
        	int x = maxHeap.top();
        	minHeap.push(x);
        	maxHeap.pop();
        	/*
        	minHeap.push(maxHeap.pop());*/
        } else if (maxHeap.size() < minHeap.size()) {
        	int x = minHeap.top();
        	maxHeap.push(x);
        	minHeap.pop();
        	/*maxHeap.push(minHeap.pop());*/
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
        	return ((maxHeap.top() + minHeap.top()) / 2.0);
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    Solution sol;
    vector<vector<int>> v = {{3, 4}, {2, 3}, {1, 2}};
    sol.findRightInterval(v);
}   