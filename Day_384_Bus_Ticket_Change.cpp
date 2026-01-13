#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array arr representing the bills customers pay with for a bus ticket costing 5 units, determine if it's possible to provide change to each customer in the order they arrive.    
// Approach: Greedy Algorithm with Count Tracking

// Steps:
// 1. Initialize two counters to keep track of the number of 5-unit and 10-unit bills
// 2. Iterate through each bill in the array
// 3. For each bill, update the counters based on the bill's denomination   
// 4. For a 10-unit bill, check if there is at least one 5-unit bill to give as change; if not, return false
// 5. For a 20-unit bill, check if there are enough smaller bills to give as change (preferably one 10-unit and one 5-unit bill, or three 5-unit bills); if not, return false
// 6. If all customers can be served with the correct change, return true

// Time Complexity: O(n) where n is the number of customers
// Space Complexity: O(1) since we are using only a fixed amount of extra space

class Solution {
  public:
     bool canServe(vector<int> &arr) {
        int das=0,panch=0;
        int N=arr.size();
        
        for(int i=0;i<N;i++){
            if(arr[i]==5){
                panch++;
            }
            else if(arr[i]==10){
                if(panch>0){
                    panch--;
                }
                else{
                    return false;
                }
                das++;
            }
            else{
                
                if(das>0&&panch>0){
                    das--;
                    panch--;
                }
                else if(panch>2){
                    panch-=3;
                }
                else{
                    return false;
                }
                
            }
            
        }
        return true;
        
    }
};