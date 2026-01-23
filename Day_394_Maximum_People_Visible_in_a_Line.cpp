#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum People Visible in a Line
// Given an array representing the heights of people standing in a line, determine the maximum number of people visible from the position of any person. A person can see another person if all the people between them are shorter.

// Approach: Use a monotonic stack to keep track of the heights of people. For each person, calculate how many people they can see to their left and right by popping from the stack until a taller person is found.    

// Steps:
// 1. Initialize a stack to help find the next taller elements.
// 2. Traverse the array to calculate the number of people visible to the left and right for each person.   
// 3. Update the maximum number of visible people found so far.
// 4. Return the maximum number of visible people.

// Time Complexity: O(N) where N is the number of people in the array (each person is pushed and popped at most once).
// Space Complexity: O(N) for the stack used.

class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        stack<int> st;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                int ind=st.top();
                st.pop();
                int l_people=st.empty()?ind+1:ind-st.top();
                int r_people=i-ind-1;
                ans=max(ans,l_people+r_people);
            }
            st.push(i);
        }
        int last=n;
        while(!st.empty()){
            int ind=st.top();
            st.pop();
            int l_people=st.empty()?ind+1:ind-st.top();
            int r_people;
            if(last<n&&arr[last]==arr[ind]){
                r_people=last-ind-1;
            }
            else{                                                 //edgecase handling
               r_people=n-ind-1; 
            }
            ans=max(ans,l_people+r_people);
            last = ind;
        }
        return ans;
    }
};