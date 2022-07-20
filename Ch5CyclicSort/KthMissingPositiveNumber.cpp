#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int counter = 1;
        int index = 0;
        while (k > 0) {
            cout << "index: " << index << "missing numbers:" << k;
            cout << "\n";x
            while (index < arr.size()) {
                while (arr[index] != counter) {
                    k--;
                    counter++;
                }
                index++;
            }
            counter++;
            k--;
        }
        return counter;
    }
};

int main() {
    Solution sol;
    vector<int> v = {2,3,4,7,11};
    cout << sol.findKthPositive(v,5);
    cout << "\n";

}