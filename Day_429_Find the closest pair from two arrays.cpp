#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two sorted arrays arr1 and arr2, and an integer x, find the pair of elements (one from each array) whose sum is closest to x. Return the pair as a vector of two integers.
Approach: We can use a two-pointer technique to solve this problem efficiently. We will initialize one pointer at the beginning of arr1 and another pointer at the end of arr2. We will calculate the sum of the elements pointed by these two pointers and compare it with x. If the sum is less than x, we will move the pointer in arr1 to the right to increase the sum. If the sum is greater than x, we will move the pointer in arr2 to the left to decrease the sum. We will keep track of the closest pair found during this process.

Steps:
1. Initialize two pointers, i and j, to the start of arr1 and the end of arr2, respectively.
2. Initialize variables a and b to store the closest pair, and a variable check to store the minimum difference found, initialized to INT_MAX.
3. While both pointers are within the bounds of their respective arrays:
    - Calculate the sum of the elements at the current pointers.
    - Calculate the absolute difference between this sum and x.
    - If this difference is less than check, update a and b with the current pair and update check with the new minimum difference. If the difference is zero, return the pair immediately as it is the closest possible.
    - If the sum is less than x, move the pointer in arr1 to the right (i++) to increase the sum.
    - If the sum is greater than x, move the pointer in arr2 to the left (j--) to decrease the sum.
4. After the loop, return the closest pair found as a vector.

Time Complexity: O(n + m), where n and m are the lengths of arr1 and arr2, respectively, since we are traversing both arrays at most once.
Space Complexity: O(1), since we are using only a constant amount of extra space to store the closest pair and the minimum difference.
*/

class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int a=0,b=0;
        int n = arr1.size();
        int m = arr2.size();     

        int i=0;
        int j=m-1;
        int check = INT_MAX;
      
        while(i<n && j>=0){
            int sum = arr1[i]+arr2[j];
            int diff = abs(sum-x);

            if(diff<check){
                a=arr1[i];
                b=arr2[j];
                if(diff==0)return {a,b};
                check=diff;
            }
            
            if(sum<x)i++;
            else j--;          
        }
        return {a,b};
    }
};