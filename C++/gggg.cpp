#include <vector>

using namespace std;
vector<int> countPositivesSumNegatives(vector<int> input) {
  vector<int> zero{};
   if (input.empty()) {
        return zero;
    }

    input.erase(remove(input.begin(), input.end(), 0), input.end());
  int sumPos = 0;
  int sumN = 0;
   for (int i = 0; i < input.size(); i++) {
        // Check if the current element is positive
        if (input[i] > 0) {
            sumPos += input[i];
        }
        // Check if the current element is negative
        else if (input[i] < 0) {
            sumN += input[i];
  }
    
  }
  vector<int> ro{sumPos, sumN};
     return ro;
}