#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given two arrays, find the count of distinct elements in the union of the two arrays.
Approach: We can use a set data structure to store the distinct elements from both arrays. 

Steps:
1. Initialize an empty set to store the distinct elements.
2. Iterate through the first array and insert each element into the set.
3. Iterate through the second array and insert each element into the set.
4. The size of the set will give us the count of distinct elements in the union of the two arrays.

Time Complexity: O(n + m) where n and m are the sizes of the two input arrays.
Space Complexity: O(n + m) in the worst case, if all elements in both arrays are distinct.

*/

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>m;
        vector<int>ans;
        
        for(int i=0;i<a.size();i++){
            if(m.count(a[i])==0){
                m[a[i]]++;
                ans.push_back(a[i]);
            }
        }
        
        for(int i=0;i<b.size();i++){
            if(m.count(b[i])==0){
                m[b[i]]++;
                ans.push_back(b[i]);
            }
        }
        
        return ans;
    }
};