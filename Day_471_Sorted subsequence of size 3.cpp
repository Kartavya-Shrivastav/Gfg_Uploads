#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, find a sorted subsequence of size 3 in the array such that the elements of the subsequence are in increasing order. If there are multiple such subsequences, return any one of them. If there is no such subsequence, return an empty array.
Approach: We can use two auxiliary arrays, small and big, to keep track of the smallest and largest elements to the left and right of each element in the array, respectively. We can then iterate through the array and check if there exists an element that is greater than the corresponding element in small and less than the corresponding element in big.

Steps:
1. Initialize two arrays, small and big, of the same size as the input array, and fill them with appropriate values (small with a large number and big with a small number).
2. Fill the small array such that small[i] contains the smallest element to the left of arr[i].
3. Fill the big array such that big[i] contains the largest element to the right of arr[i].
4. Iterate through the array and check if there exists an index i such that arr[i] is greater than small[i] and less than big[i]. If such an index exists, return the subsequence {small[i], arr[i], big[i]}.
5. If no such index exists, return an empty array.

Time Complexity: O(n) - We traverse the array three times, once for filling the small array, once for filling the big array, and once for checking the conditions.
Space Complexity: O(n) - We use two auxiliary arrays of the same size as the input array.
*/

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n=arr.size();
        vector<int>small(n, 1e9), big(n, -1e9);
        
        small[0]=arr[0];
        for(int i=1; i<n; i++){
            small[i]=min(small[i-1], arr[i]);
        }
        
        big[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            big[i]=max(big[i+1], arr[i]);
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]>small[i] && arr[i]<big[i]){
                return {small[i], arr[i], big[i]};
            }
        }
        return {};
    }
};