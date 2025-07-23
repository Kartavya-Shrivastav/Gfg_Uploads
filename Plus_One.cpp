#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Increment an integer represented as an array of digits.
// Approach: Traverse the array from the end, incrementing the last digit and handling carry if it exceeds 9.

// Steps:
// 1. Start from the last digit of the array.
// 2. If the digit is less than 9, simply increment it and return the array.
// 3. If the digit is 9, set it to 0 and continue to the next digit to handle carry.
// 4. If all digits are 9, create a new array with an additional digit at the start set to 1 and the rest set to 0.
// 5. Return the modified array.

// Time Complexity: O(n) — where `n` is the size of the array.
// Space Complexity: O(1) — no additional space is used apart from a few variables.

class Solution {
  public:
    vector<int> increment(vector<int> arr, int N) {
        for (int i = N - 1; i >= 0; --i) {
            if (arr[i] < 9) {
                arr[i]++;
                return arr;
            } else {
                arr[i] = 0;
            }
        }
        vector<int> result(N + 1);
        result[0] = 1;
        return result;
    }
};