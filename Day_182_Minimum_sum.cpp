#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the minimum sum that can be formed by pairing the integers and summing them up.
// Approach: We can sort the array and then pair the largest elements with the smallest elements to
// minimize the sum. The result is built by taking pairs from the end of the sorted array and summing them up, handling carry as needed.

// Steps:
// 1. Sort the array in ascending order.
// 2. Initialize an empty string to store the result and a carry variable to handle sums greater than 9.
// 3. Iterate through the array from the end, taking pairs of elements.
// 4. For each pair, calculate the sum and handle the carry.
// 5. Append the last digit of the sum to the result string and update the carry
// 6. If there's a carry left after processing all pairs, append it to the result.
// 7. Reverse the result string to get the final answer.


class Solution {
  public:
    string minSum(vector<int> &arr) {
        string ans;
        int carry = 0;
        sort(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= 0; i -= 2) {
            int sum = (arr[i] + (i - 1 >= 0 ? arr[i - 1] : 0) + carry);
            ans.push_back('0' + (sum % 10));
            carry = (sum / 10);
        }
        if (carry) ans.push_back('0' + carry);
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};