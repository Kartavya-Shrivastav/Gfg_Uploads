#include <bits/stdc++.h>
using namespace std;

// Probblem: Given two integers n and d, return the count of all numbers in the range [1, n] that have a specific difference d between the number and the sum of its digits.
// Approach: We can use binary search to find the smallest number in the range [1, n] that satisfies the condition (number - sum of its digits) >= d. Once we find this number, we can calculate the count of numbers that satisfy the condition by subtracting this number from n and adding 1 (to include the number itself).

// Steps:
// 1. Initialize two pointers, l and r, to represent the range of numbers we are searching through. Set l to 10 (the smallest two-digit number) and r to n.
// 2. Use a while loop to perform binary search until l is less than or equal to r.
// 3. Calculate the mid-point of the current range and compute the sum of its digits.
// 4. Check if the condition (mid - sum of its digits) >= d is satisfied. If it is, update the result and move the right pointer to mid - 1 to search for smaller numbers. If it is not, move the left pointer to mid + 1 to search for larger numbers.
// 5. After the loop, calculate the count of numbers that satisfy the condition by subtracting the found number from n and adding 1.
// 6. Return the count.

// Time Complexity: O(log n * log n) - The binary search takes O(log n) and calculating the sum of digits takes O(log n) in the worst case.
// Space Complexity: O(1) - We are using a constant amount of space for variables.
class Solution {
  public:
    int getCount(int n, int d) {
        if(d >= n) return 0;
       
        int l = 10, r = n;
        int num = n+1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            int cnt = mid;
            int sum = 0;
            
            while(cnt>0){
                sum += cnt%10;
                cnt = cnt/10;
            }
            
            if((mid-sum) >= d){
                num = mid;
                r = mid-1;
            }
            else  l = mid+1;
            
        }
        
        return n-num+1;
    }
};