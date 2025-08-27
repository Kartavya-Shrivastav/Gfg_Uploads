#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=2; i<arr.size(); i++){
            int l = 0, r = i-1;
            
            while(l < r){
            
                if(arr[l]+arr[r] > arr[i]){
                    ans += r - l;
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        
        return ans;
    }
};

