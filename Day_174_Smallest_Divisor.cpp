#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest divisor of the array such that the sum of the quotients is less than or equal to k


class Solution {
    public:
        int smallestDivisor(vector<int>& arr, int k) {
                // Find the smallest divisor such that the sum of quotients is <= k
                int n = arr.size();
                int low = 1; // Smallest possible divisor
                int maxE = *max_element(arr.begin(), arr.end()); // Largest element in array
                int high = maxE + k; // Upper bound for binary search
                int ans = high; // Initialize answer with upper bound
                while(low <= high){
                        int mid = low + (high - low)/2; // Current divisor to check
                        int count = 0; // Sum of quotients
                        for(auto &e : arr){
                                count += ceil((double)e/mid); // Add quotient for each element
                        }
                        if(count <= k){
                                // If sum of quotients is within limit, try smaller divisor
                                ans = min(mid, ans);
                                high = mid - 1;
                        }else{
                                // Otherwise, try larger divisor
                                low = mid + 1;
                        }
                }
                return ans; // Return the smallest valid divisor
        }
};