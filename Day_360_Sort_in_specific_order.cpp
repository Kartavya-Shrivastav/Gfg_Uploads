#include <bits/stdc++.h>
using namespace std;

// Problem: Sort an array such that all odd numbers are sorted in descending order and all even numbers are sorted in ascending order, with odd numbers appearing before even numbers.
// Approach: Use a custom comparator in the sort function to achieve the desired order.

// Steps:
// 1. Define a custom comparator that:
//    - Places odd numbers before even numbers.
//    - Sorts odd numbers in descending order.
//    - Sorts even numbers in ascending order.
// 2. Use the sort function with the custom comparator to sort the array.
// 3. Return or print the sorted array.

// Complexity Analysis:
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) if sorting in place

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(), [](int &a, int &b){
            if(a%2==b%2 && a%2==0)return a<b;
            else if(a%2==b%2 && a%2==1)return a>b;
            return a%2==1;
        });
    }
};