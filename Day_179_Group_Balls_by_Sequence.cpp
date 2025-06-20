#include <bits/stdc++.h>
using namespace std;

// Problem: Valid Grouping
// Approach: Use a map to count the frequency of each number and a set to track unique numbers.

// Steps:
// 1. Count the frequency of each number in the array using a map.
// 2. Use a set to store unique numbers.
// 3. For each unique number, check if we can form a valid group of size k.
// 4. If we can form a valid group, reduce the frequency of the numbers in the map.
// 5. If we cannot form a valid group, return false.
// 6. If all groups can be formed, return true.

// Time Complexity: O(N * K) where N is the number of elements in the array and K is the size of the group.
// Space Complexity: O(N) for the map and set.

class Solution {
    public:
        // Function to check if the array can be divided into groups of size k with consecutive numbers
        bool validgroup(vector<int> &arr, int k) {
                map<int,int> mpp; // Map to store frequency of each number
                set<int> st;      // Set to store unique numbers in sorted order
                
                // Count frequency and collect unique numbers
                for(int i = 0; i < arr.size(); i++){
                        mpp[arr[i]]++;
                        st.insert(arr[i]);
                }
                
                // Try to form groups starting from the smallest unique number
                for(auto it : st){
                        int freq = mpp[it]; // Frequency of current number
                        if(freq == 0) continue; // Already used in previous groups
                        // Check if we can form a group of size k starting from 'it'
                        for(int j = it; j < it + k; j++){
                                if(mpp[j] < freq) // Not enough numbers to form a group
                                        return false;
                                else {
                                        mpp[j] -= freq; // Use up 'freq' numbers for this group
                                }
                        }
                }
                return true; // All groups formed successfully
        }
};