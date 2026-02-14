#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers arr and an integer k, return the minimum time required to paint all the boards by k painters. Each painter can only paint contiguous sections of the board, and the time taken to paint a board is equal to the length of the board. The painters can start painting at the same time, and they can only paint one board at a time.
// Approach: We can use binary search to find the minimum time required to paint all the boards. The minimum time will be at least the maximum length of a single board (since a painter cannot paint more than one board at a time), and at most the sum of all board lengths (if one painter paints all the boards). We can define a function that checks if it is possible to paint all the boards within a given time limit using k painters. We can then use binary search to find the minimum time for which this function returns true.

// Steps:
// 1. Initialize low to the maximum length of a single board and high to the sum of all board lengths.
// 2. Use a while loop to perform binary search until low is less than or equal to high.
// 3. Calculate the mid-point of the current range and check if it is possible to paint all the boards within this time limit using k painters.
// 4. If it is possible, update the result and move the high pointer to mid - 1 to search for a smaller time limit. If it is not possible, move the low pointer to mid + 1 to search for a larger time limit.
// 5. After the loop, return the result.

// Time Complexity: O(n log m) - where n is the number of boards and m is the sum of all board lengths. The binary search takes O(log m) and the function to check if it is possible to paint within a time limit takes O(n).
// Space Complexity: O(1) - We are using a constant amount of space for variables

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        int n = (int)arr.size();
        int low = *max_element(arr.begin(),arr.end());
        int s = 0;
        for(auto it:arr)
        {
            s+=it;
        }
        
        
        auto f = [&](int mid)->int{
            
            int curr = 0;
            int count = 1;
            for(int i=0;i<n;i++)
            {
                if((curr+arr[i])<=mid)
                {
                    curr+=arr[i];
                }
                else
                {
                    curr = arr[i];
                    count ++;
                }
            }
            return (count<=k);
        };
        int high  = s;
        int res = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(f(mid))
            {
                res = mid ;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
};