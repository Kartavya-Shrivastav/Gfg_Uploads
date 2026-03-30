#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.  
Approach: We can use a stack to keep track of the indices of the elements in the array. We will iterate through the array from right to left and for each element, we will pop elements from the stack until we find an element that is less than or equal to the current element. The index of the last popped element will be stored in a vector v. We will also maintain a vector ans to store the sum of minimums for each subarray ending at the current index. Finally, we will sum up all the values in ans and return the result modulo 10^9 + 7.

Steps:
1. Initialize a stack to keep track of indices and two vectors v and ans to store the indices of the last popped elements and the sum of minimums for each subarray respectively.
2. Iterate through the array from right to left and for each element, pop elements from the stack until we find an element that is less than or equal to the current element. Store the index of the last popped element in vector v.
3. For each element, calculate the sum of minimums for the subarray ending at that index using the values in vector v and store it in vector ans.
4. Finally, sum up all the values in ans and return the result modulo 10^9 + 7.

Time complexity of this approach is O(n) and the space complexity is O(n).   
Space complexity is O(n) because we are using two additional vectors of size n to store the indices and the sum of minimums for each subarray.

*/

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        stack<int>s;
        vector<int>v(n,-1);
        vector<int>ans(n,0);
        int temp = 0;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                v[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            
            if(v[i]==-1){
                ans[i] = (i+1)*arr[i];
            }
            else{
                int k = i-v[i];
                ans[i]=arr[i]*k;
                ans[i]+=ans[v[i]];
            }
            
            temp+=ans[i];
        }
        
        return temp;
    }
};