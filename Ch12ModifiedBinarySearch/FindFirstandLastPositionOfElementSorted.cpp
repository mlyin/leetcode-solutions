#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int firstPosition(vector<int>& nums, int target) {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        int pos = -1;
        while (left <= right) {
            mid = (left+right) / 2;
            if (nums[mid] == target) {
                pos = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return pos;
    }

    int lastPosition(vector<int>& nums, int target) {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        int pos = -1;

        while (left <= right) {
            mid = (left+right) / 2;
            if (nums[mid] == target) {
                pos = mid;
                left = mid +1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return pos;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int firstIndex = firstPosition(nums, target);
        int secondIndex = lastPosition(nums, target);
        res.push_back(firstIndex);
        res.push_back(secondIndex);
        return res;
    }
};