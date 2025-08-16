#include <bits/stdc++.h>
using namespace std;

// Problem: Insert a new interval into a list of intervals and merge overlapping intervals
// Approach: Append the new interval, sort all intervals, then merge overlapping ones by comparing boundaries

// Steps:
// 1. Add the new interval to the list of intervals.
// 2. Sort the intervals by their starting points.
// 3. Traverse the sorted list and check for overlaps between consecutive intervals.
// 4. If intervals overlap, merge them by updating the start and end boundaries accordingly.
// 5. Mark merged intervals with a sentinel value (-1) to skip them later.
// 6. Collect all valid intervals (non -1) into the result list.
// 7. Return the merged list of intervals.

// Time Complexity: O(n log n) — due to sorting the intervals, where n is the number of intervals.
// Space Complexity: O(n) — for storing the merged list of intervals.

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &itrl, vector<int> &nitr) {

        itrl.push_back(nitr);
        int n=itrl.size();
        sort(itrl.begin(),itrl.end());
        for(int i=1;i<n;i++){
            auto x=itrl[i-1];
            auto y=itrl[i];
            if(x[1]>=y[0]){
                if(x[1]>=y[1]){
                    itrl[i]=itrl[i-1];
                    itrl[i-1][0]=-1;
                }
                else{
                    itrl[i][0]=itrl[i-1][0];
                    itrl[i-1][0]=-1;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:itrl){
            if(i[0]!=-1)ans.push_back(i);
        }
        return ans;
    }
};