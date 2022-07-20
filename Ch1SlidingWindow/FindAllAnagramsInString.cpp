using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> map;
        for (char c : p) {
          map[c]++;
        }
        int count = p.length();
        int left = 0; 
        int right = 0;
        char chars[s.length()];
        for (int i = 0; i < s.length(); i++) {
          chars[i] = s[i];
        }
        while (right < s.length()) {
          if (map[chars[right++]]-- > 0) {
            count--;
          }
          while (count == 0) {
            if (right - left == p.length()) {
              res.push_back(left);
              map[chars[left++]]++;
            } else {
              map[chars[left++]]++;
            }
          }
        }
        return res;
    }
};

int main() {
  Solution sol;
  string s1 = "cbaebabacd";
  string s2 = "abc";
  for (auto x : sol.findAnagrams(s1, s2)) {
    cout << x << " ";
  }
  cout << "\n";
}
