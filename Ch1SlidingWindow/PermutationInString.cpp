using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        for (char c : s1) {
          map[c]++;
        }
        int count = s1.length();
        int left = 0; 
        int right = 0;
        char chars[s2.length()];
        for (int i = 0; i < s2.length(); i++) {
          chars[i] = s2[i];
        }
        while (right < s2.length()) {
          if (map[chars[right++]]-- > 0) {
            count--;
          }
          while (count == 0) {
            if (right - left == s1.length()) {
              return true;
            } else {
              map[chars[left++]]++;
            }
          }
        }
        return false;
    }
};


int main() {
  Solution sol;
}