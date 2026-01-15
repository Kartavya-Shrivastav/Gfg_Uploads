#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array representing the ratings of children, distribute candies such that each child has at least one candy and children with a higher rating than their immediate neighbors receive more candies. Find the minimum number of candies needed.
// Approach: We traverse the ratings array while identifying increasing and decreasing sequences. We maintain counts for peaks and valleys to ensure the candy distribution rules are met.

// Steps:
// 1. Initialize the total candy count.
// 2. Traverse the ratings array to identify increasing and decreasing sequences.
// 3. For increasing sequences, incrementally assign more candies.
// 4. For decreasing sequences, do the same but ensure the peak has enough candies.
// 5. Adjust the total count if the decreasing sequence is longer than the peak to satisfy the conditions.

// Time Complexity: O(N) where N is the number of children.
// Space Complexity: O(1) as we use a constant amount of extra space.

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n=arr.size();
        int sum=1;
        int i=1;

        while(i<n){
            if(arr[i]==arr[i-1]){
                sum+=1;
                i++;
            }

            int peak=1;
        
            while(i<n&&arr[i]>arr[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
        
            int down=1;
        
            while(i<n&&arr[i]<arr[i-1]){
                sum+=down;
                down++;
                i++;
            }

            if(down>peak){
                sum+=(down-peak);
            }
        }

        return sum;
    }
};