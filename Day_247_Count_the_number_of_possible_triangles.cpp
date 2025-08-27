#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count the number of possible triangles
    int countTriangles(vector<int>& arr) {
        int ans = 0;
        // Sort array to make triangle detection easier
        sort(arr.begin(), arr.end());
        
        // For each possible largest side of triangle
        for(int i=2; i<arr.size(); i++){
            // Use two pointers to find other two sides
            int l = 0, r = i-1;
            
            while(l < r){
                // If sum of two sides > third side, we found valid triangles
                // All numbers between l and r will also form valid triangles
                if(arr[l]+arr[r] > arr[i]){
                    ans += r - l;
                    r--;
                }
                else{
                    // If sum <= third side, need larger numbers
                    l++;
                }
            }
        }
        
        return ans;
    }
};

