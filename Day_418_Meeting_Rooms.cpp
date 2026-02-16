#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
// Approach: We can sort the intervals based on their start times. Then, we can iterate through the sorted intervals and check if there is any overlap between consecutive intervals. If we find any overlap, it means that the person cannot attend all meetings, and we return false. If we finish checking all intervals without finding any overlap, we return true.

// Steps:
// 1. Sort the intervals based on their start times.
// 2. Iterate through the sorted intervals starting from the second interval, and for each interval, check if the end time of the previous interval is greater than the start time of the current interval. If it is, return false.
// 3. If we finish checking all intervals without finding any overlap, return true.
// 4. Return the result as a boolean value indicating whether the person can attend all meetings or not. 
// Time Complexity: O(n log n) - due to sorting the intervals. The iteration through the intervals takes O(n).
// Space Complexity: O(1) - We are using a constant amount of space for variables

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());
        for(int i = 1;i<arr.size();i++){
            if(arr[i-1][1]>arr[i][0])return false;
        }
        return true;
    }
};