#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int> arr) {
            int len = arr.size();
            int ans=arr[0];
            for(int i=1;i<len;i++){
                ans^=arr[i]^i;
            }
            return ans;
    }
};
