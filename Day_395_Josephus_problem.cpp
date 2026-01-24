#include <bits/stdc++.h>
using namespace std;

// Problem: Josephus Problem
// Given n people numbered from 1 to n standing in a circle and a number k, eliminate every k-th person until only one person remains. Find the position of that person.
// Approach: Use an iterative method to find the position of the last remaining person. The position can be determined using the relation:
// J(n, k) = (J(n-1, k) + k) % n, with base case J(1, k) = 0.

// Steps:
// 1. Initialize a variable to store the position of the last remaining person.
// 2. Iterate from 1 to n, updating the position using the relation mentioned above.
// 3. Return the position adjusted for 1-based indexing.

// Time Complexity: O(N) where N is the number of people.
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
  public:
    int josephus(int n, int k) {
        int i=1, ans = 0;
        while (i<=n){
            ans = (ans+k) % i;
            i++;
        }
        
        return ans+1;
    }
};