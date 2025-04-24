#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> nums){
        int xxory=0;
        
        for(auto it: nums)
        xxory=xxory^it;
        int number=xxory & -xxory;
        int x=0;
        int y=0;
        for(auto it:nums){
            if(it & number){
                x=x^it;
            }
            else{
                y=y^it;
            }
        }
        nums.clear();
        if(x>y){
            nums.push_back(y);
            nums.push_back(x);
            return nums;
        }
        else{
            nums.push_back(x);
            nums.push_back(y);
            return nums;
        }
     }
};