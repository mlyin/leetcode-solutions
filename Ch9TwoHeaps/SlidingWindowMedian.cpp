#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T, class Container = vector<T>, class Compare = less<typename Container::value_type>>
class priority_queue_with_remove : public priority_queue<T, Container, Compare> {
    public:
        bool remove (const T &valueToRemove) {
            auto itr = find(this->c.begin(), this->c.end(), valueToRemove);
            if (itr == this->c.end()) {
                return false;
            }
            this->c.erase(itr);
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
};

class Solution {
public:
    priority_queue_with_remove<int> maxHeap;
    priority_queue_with_remove<int, vector<int>, greater<int>> minHeap;
    void rebalanceHeaps() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result(nums.size()-k+1);
        for (int i = 0; i < nums.size(); i++) {
            if (maxHeap.size() == 0 || maxHeap.top() >= nums[i]) {
                maxHeap.push(nums[i]);
            } else {
                minHeap.push(nums[i]);
            }
            rebalanceHeaps();

            if (i - k + 1 >= 0) { // if we have at least k elements in the sliding window
                if (maxHeap.size() == minHeap.size()) {
                    result[i - k + 1] = ((maxHeap.top() + minHeap.top()) / 2.0);
                } else {
                    result[i - k + 1] = maxHeap.top();
                }
            }

            int elementToRemove = nums[i - k + 1];
            if (elementToRemove < maxHeap.top()) {
                maxHeap.remove(elementToRemove);
            } else {
                minHeap.remove(elementToRemove);
            }
            rebalanceHeaps();
        }
        return result;
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
    vector<int> v ={1,3,-1,-3,5,3,6,7};
    sol.medianSlidingWindow(v, 3);
}   