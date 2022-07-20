using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      unordered_map<int, int> count;
      int maxFruits = 0;
      for (int start = 0, end = 0; end < fruits.size(); end++) {
        count[fruits[end]]++;
        while (count.size() > 2) {
          count[fruits[start]]--;
          if (count[fruits[start]] == 0) {
            count.erase(fruits[start]);
          }
          start++;
        }
        maxFruits = max(maxFruits, end - start + 1);
      }
      return maxFruits;
    }
};


int main() {
	Solution sol;
  vector<int> v = {3,3,3,1,2,1,1,2,3,3,4};
  cout << sol.totalFruit(v);
}
