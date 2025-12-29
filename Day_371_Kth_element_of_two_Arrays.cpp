#include <bits/stdc++.h>
using namespace std;

// Problem: Kth Element of Two Sorted Arrays
// Approach: Two Pointers

// Steps:
// 1. Use two pointers to traverse both arrays.
// 2. Compare the elements at both pointers and move the pointer of the smaller element.
// 3. Keep a count of the number of elements processed.
// 4. When the count reaches k, return the current element.
// 5. If one array is exhausted, continue with the other array until k elements are processed.
// 6. Return the kth element found.

// Time Complexity: O(k) in the worst case
// Space Complexity: O(1)

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n1=a.size();
        int n2=b.size();
        int ind1=0,ind2=0, cnt=0;
        while(ind1<n1 && ind2<n2){
            if(a[ind1]<=b[ind2]){
                if(cnt==k-1)return a[ind1];
                ind1++;
            }else{
                if(cnt==k-1)return b[ind2];
                ind2++;
            }
            cnt++;
        }
        while(ind1<n1){
            if(cnt==k-1)return a[ind1];
            ind1++;
            cnt++;
        }
        while(ind2<n2){
            if(cnt==k-1)return b[ind2];
            ind2++;
            cnt++;
        }
        return -1;
    }
};