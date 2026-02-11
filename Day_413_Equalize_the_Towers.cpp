#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: You are given two arrays: heights[] and cost[], each of size n. You can change every height to a common target height h. Changing a height from x to h costs abs(x - h) * cost[i]. The task is to find the minimum total cost required to make all heights equal.
Approach: The total cost function is convex with respect to the target height h. Therefore, the minimum cost occurs at a specific optimal height value. Instead of checking all possible heights linearly, we can apply binary search over the range of possible heights (from minimum to maximum height in the array). For each mid value, we compute the cost for heights mid-1, mid, and mid+1 to determine the direction in which the cost decreases. This allows us to efficiently converge to the minimum cost.

Steps:
1. Find the minimum and maximum values from the heights[] array to define the search range.
2. Use binary search between this range [s, e].
3. For each middle value m, compute:
    cost for height m-1
    cost for height m
    cost for height m+1
4. If the cost at m is less than or equal to both neighbors, it is the minimum — return it.
5. If cost at m is greater than cost at m-1, move the search range to the left.
6. Otherwise, move the search range to the right.
7. Continue until the optimal height giving minimum cost is found.

Time Complexity: O(n log R), where n is the number of elements in the array and R is the range of height values (max height – min height). Binary search runs in log R iterations and each iteration requires O(n) cost computation.
Space Complexity: O(1), only constant extra space is used apart from input arrays.

*/

class Solution {
  public:
    virtual int fun(int h, vector<int>& heights, vector<int>& cost){
      int sum=0;
      int i=0;
      for(int x: heights){
        sum += ((abs(x-h))*cost[i]);
        i++;
      }
      
      return sum;
    }
    
    virtual int minCost(vector<int>& heights, vector<int>& cost) {
      int e=INT_MIN, s=INT_MAX;
      
      for(int &x: heights){
        e = max(e, x);  
        s = min(s, x);  
      }
      
      int ans=INT_MAX;

      while(s<=e){
        int m=s+(e-s)/2;
        
        int p=fun(m-1, heights, cost);
        int c=fun(m, heights, cost);
        int n=fun(m+1, heights, cost);
        
        if(c<=p && c<=n){
          ans=c;
          return ans;
        }
        if(c>p && c<=n) e=m-1;
        else s=m+1;
      }
      
      return ans;
    }
};