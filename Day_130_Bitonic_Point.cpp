#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximum(vector<int> &arr) {
        return *max_element(arr.begin(),arr.end());;
    }
};
