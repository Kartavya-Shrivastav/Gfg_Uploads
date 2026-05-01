#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two 2D vectors representing the preferences of n men and n women, where men[i] is a list of the preferences of the i -th man and women[i] is a list of the preferences of
Approach: We can use the Gale-Shapley algorithm to solve the stable marriage problem. The algorithm works as follows:

Steps:
1. Initialize all men and women as free (not engaged).
2. While there are free men:
    a. Select a free man (let's call him "man").
    b. Let "woman" be the first woman in "man"'s preference list that he hasn't proposed to yet.
    c. If "woman" is free, then engage "man" and "woman".
    d. If "woman" is not free, then check if "woman" prefers "man" over her current partner.
    e. If "woman" prefers "man" over her current partner, then break the engagement and engage "man" and "woman".
    f. If "woman" does not prefer "man" over her current partner, then add "man" back to the list of free men.
3. The algorithm terminates when there are no free men left, and the resulting engagements represent a stable matching.

Time Complexity: O(n^2) - Each man can propose to each woman at most once, and there are n men and n women. 
Space Complexity: O(n^2) - We use a 2D vector to store the preferences of the men and women.
*/

class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n=men.size();
        
        vector<int>usedMen(n, -1);
        vector<int>usedWomen(n, -1);
        
        queue<int>unusedMen;
        
        vector<vector<int>>rank(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                rank[i][women[i][j]]=j;
            }
        }
        
        vector<int>menAt(n, 0);
        
        for(int i=0; i<n; i++){
            unusedMen.push(i);
        }
        
        while(!unusedMen.empty()){
            int node=unusedMen.front();
            unusedMen.pop();
            
            int woman=men[node][menAt[node]];
            menAt[node]++;
            
            if(usedWomen[woman]==-1){
                usedWomen[woman]=node;
                usedMen[node]=woman;
            }else{
                int currentMan=usedWomen[woman];
                if(rank[woman][currentMan]>rank[woman][node]){
                    usedWomen[woman]=node;
                    usedMen[node]=woman;
                    
                    unusedMen.push(currentMan);
                    usedMen[currentMan]=-1;
                }else{
                    unusedMen.push(node);
                }
            }
        }
        return usedMen;
    }
};