using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int minNumberOfConsecutives = 10000;
    int currentSum = 0;
    int startingIndex = 0;
    for (int endingIndex = 0; endingIndex < arr.size(); endingIndex++) {
      currentSum += arr[endingIndex];
      while (currentSum >= S) {
        minNumberOfConsecutives = min(endingIndex - startingIndex + 1, minNumberOfConsecutives);
        currentSum -= arr[startingIndex];
        startingIndex++;
      }
    }
    if (minNumberOfConsecutives != 10000) {
      return minNumberOfConsecutives;
    } else {
      return 0;
    }
  }
};


int main(int argc, char* argv[]) {
  int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
}