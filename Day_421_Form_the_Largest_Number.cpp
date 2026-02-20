#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of non-negative integers, arrange them such that they form the largest number.
// Approach: We can convert the integers to strings and then sort them based on a custom comparator. The comparator will compare two strings by concatenating them in both possible orders and checking which concatenation is larger. After sorting, we can concatenate the sorted strings to form the largest number. We also need to handle the case where all numbers are zero, in which case we should return "0".

// Steps:
// 1. Convert each integer in the input array to a string and store them in a vector of strings.
// 2. Sort the vector of strings using a custom comparator that compares the concatenation of two strings in both possible orders.
// 3. After sorting, check if the largest string is "0". If it is, return "0" since all numbers are zero.
// 4. Otherwise, concatenate all the sorted strings to form the largest number and return it.

// Time Complexity: O(n log n) due to the sorting step, where n is the number of integers in the input array.
// Space Complexity: O(n) for storing the string representations of the integers.

class Solution {
  public:
    static bool comp(string a, string b) {
         return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        vector<string> nums;

        // Convert each number to string
        for (int i = 0; i < arr.size(); i++) {
            nums.push_back(to_string(arr[i]));
        }

        // Sort using custom comparator
        sort(nums.begin(), nums.end(), comp);

        // Handle case when all numbers are zero
        if (nums[0] == "0") {
            return "0";
        }

        // Concatenate result
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
        }

        return ans;
    }
};

 