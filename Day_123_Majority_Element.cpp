#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        n = n / 2;
        for(unordered_map<int,int>::iterator it = mp.begin();
        it != mp.end(); it++)
        {
            if(it->second > n)
                return it->first;
        }
        return -1;
    }
};
