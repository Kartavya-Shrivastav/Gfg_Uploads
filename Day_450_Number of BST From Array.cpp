#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, count the number of unique binary search trees (BSTs) that can be formed using the elements of the array as nodes. The structure of the BST should be such that it maintains the properties of a binary search tree.
Approach: To solve this problem, we can use dynamic programming to count the number of unique BSTs that can be formed with a given number of nodes. The number of unique BSTs that can be formed with 'n' nodes is given by the nth Catalan number, which can be calculated using the formula:
C(n) = (2n)! / ((n + 1)! * n!)

Steps:
1. Sort the input array to ensure that the elements are in the correct order for forming BSTs.
2. Create a dynamic programming array 'cat' of size n+1, where cat[i] will store the number of unique BSTs that can be formed with 'i' nodes.
3. Initialize cat[0] and cat[1] to 1, as there is only one unique BST that can be formed with 0 or 1 node.
4. Fill the 'cat' array using a nested loop:
    - For each number of nodes 'i' from 2 to n, calculate the number of unique BSTs by summing the products of the number of BSTs formed by the left and right subtrees for all possible splits of the nodes.
5. For each element in the input array, determine its index in the sorted array to find out how many nodes would be in the left and right subtrees if that element were the root of the BST.
6. Use the 'cat' array to calculate the number of unique BSTs for each element based on the number of nodes in the left and right subtrees and store the results in the answer array.

Time Complexity: O(n^2) for filling the 'cat' array, and O(n log n) for sorting the input array. Overall, the time complexity is O(n^2).
Space Complexity: O(n) for the 'cat' array and the answer array, resulting in O(n) overall.
*/


class Solution {
  public:
    virtual vector<int> countBSTs(vector<int>& arr){
      vector<int> ans;
      
      int n=arr.size();
      vector<long long int> cat(n+1, 0);
      cat[0]=cat[1]=1;
      
      vector<int> v=arr;
      sort(v.begin(), v.end());
      
      for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
          cat[i] += (cat[j]*cat[i-1-j]);    
        }  
      }
      
      for(int i=0; i<n; i++){
        int ind=lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        int l=ind-0;
        int r=n-1-ind;
        
        ans.push_back((int)(cat[l]*cat[r]));
        
      }
      
      return ans;
      
    }
};