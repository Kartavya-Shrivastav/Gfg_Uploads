#include <bits/stdc++.h>
using namespace std;

// Problem: Given two integer arrays gas and cost, where gas[i] is the amount of gas at station i and cost[i] is the cost to travel from station i to the next station, find the starting gas station index from which you can complete a full circuit. If it's not possible, return -1.
// Approach: Use a greedy algorithm to track the total gas and cost, and determine the starting station by resetting when the current gas balance drops below zero.

// Steps:
// 1. Calculate the total gas and total cost. If total gas is less than total cost, return -1 as it's impossible to complete the circuit.
// 2. Initialize variables to track the current gas balance and the starting station index.
// 3. Iterate through each gas station, updating the current gas balance by adding gas[i] and subtracting cost[i].
// 4. If at any point the current gas balance drops below zero, reset the starting station to the next station and reset the current gas balance to zero.
// 5. After completing the loop, return the starting station index as the answer.
// 6. If no valid starting station is found, return -1.

// Time Complexity: O(n), where n is the number of gas stations, as we make a single pass through the arrays.
// Space Complexity: O(1), as we use a constant amount of extra space.

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
          int n=gas.size(),total=0;
       for(int i=0;i<n;i++){
           total+= gas[i] - cost[i];
       }
       
       if(total<0) return -1;
       
       int res=0;
       total=0;
      for(int i=0;i<n;i++){
          total+=gas[i] - cost[i];
          if(total<0) {res=i+1; total=0;} //means this index aint answer, prolly next one is
       }
       
        return res;
    }
};
