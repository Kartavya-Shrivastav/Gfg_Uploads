#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two sorted arrays, find the intersection of the two arrays. The intersection should contain only unique elements.
Approach: We can use two pointers to traverse both arrays simultaneously. If the elements at both pointers are equal, we add the element to the result and move both pointers. If the element at the first pointer is smaller, we move the first pointer. If the element at the second pointer is smaller, we move the second pointer.

Steps:
1. Initialize two pointers, i and j, to 0.
2. Initialize an empty vector result to store the intersection.
3. While both pointers are within the bounds of their respective arrays:
    a. If a[i] is equal to b[j], check if the result is empty or if the last element in the result is not equal to a[i]. If so, add a[i] to the result. Move both pointers i and j.
    b. If a[i] is less than b[j], move pointer i.
    c. If a[i] is greater than b[j], move pointer j.
4. Return the result vector.

Time Complexity: O(n + m) - We traverse both arrays at most once, where n and m are the lengths of the two arrays.
Space Complexity: O(k) - The space complexity is O(k) where k is the number of unique elements in the intersection of the two arrays. In the worst case, k can be min(n, m) if all elements are common and unique.
*/

class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int>result;
       
        int i = 0,j = 0;
       while(i < a.size() && j < b.size()){
            if(a[i] == b[j] ){
                if (result.empty() || result.back() != a[i]) {
                     result.push_back(a[i]);
                  }
                i++;j++;
            }else if(a[i] > b[j]){
               j++;
           }else{
               i++;
           }
       }
       return result;
    }
};