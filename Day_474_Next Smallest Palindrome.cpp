#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of digits representing a number, find the next smallest palindrome larger than the given number.
Approach: 

Steps:
1. Check if all digits are 9. If they are, the next palindrome would be 100...001 (1 followed by n-1 zeros and another 1).
2. If not all digits are 9, we can find the next palindrome by mirroring the left half of the number to the right half.
    - For odd length numbers, we can compare the left half with the right half. If the left half is greater than the right half, we can simply mirror the left half to the right half. If the left half is less than or equal to the right half, we need to increment the middle digit (or the left half) and then mirror it to the right half.
    - For even length numbers, we can compare the left half with the right half. If the left half is greater than the right half, we can simply mirror the left half to the right half. If the left half is less than or equal to the right half, we need to increment the left half and then mirror it to the right half.  
3. Return the resulting palindrome.

Time Complexity: O(n) - We may need to traverse the number a few times (to check for 9s, to mirror, and to increment), but overall it is linear with respect to the number of digits.
Space Complexity: O(n) - We are creating a new array to store the next palindrome, which takes linear space with respect to the number of digits.
*/

class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n=num.size();
        bool is9 = true;
        for(auto& x:num){
            if(x!=9){
                is9 = false;
            }
        }
        if(is9){
            vector<int> res(n+1, 0);
            res[0]=1;
            res[n]=1;
            return res;
        }
        
        vector<int> ans = num;
        int l=0; 
        int r=n-1;
        int mid = l+(r-l)/2;
        if(n%2!=0){ //odd
            l = mid-1;
            r = mid+1;
            bool inc = false;
            bool same = false;
            while(r<n && l>=0){
                if(num[l]>num[r]){
                    inc = true;
                    break;
                }
                else if(num[l]<num[r]){
                    inc = false;
                    break;
                }
                else{
                    r++;
                    l--;
                }
            }
            if(r==n){
                same = true;
            }
            
            l=0;
            r=n-1;
            while(l<mid){
                ans[r] = ans[l];
                r--;
                l++;
            }
            
            l=mid;
            r=mid;
            if(!inc || same){
                if(ans[mid]==9){
                    while(l>=0 && r<n && ans[l]==9 && ans[r]==9){
                        ans[l]=0;
                        ans[r]=0;
                        l--;
                        r++;
                    }
                    if(l>=0 && r<n){
                        ans[l]++;
                        ans[r]++;
                    }
                }
                else{
                    ans[mid]++;
                    return ans;
                }
            }
        }
        else{
            // mid = mid-1;
            l=mid-1;
            r=mid+2;
            bool inc = false;
            bool same = false;
            while(l>=0 && r<n){
                if(num[l]>num[r]){
                    inc = true;
                    break;
                }
                else if(num[l]<num[r]){
                    inc = false;
                    break;
                }
                else{
                    r++;
                    l--;
                }
            }
            if(r==n){
                same = true;
            }
            
            l=0;
            r=n-1;
            while(l<mid){
                ans[r] = ans[l];
                r--;
                l++;
            }
            
            l=mid;
            r=mid+1;
            if(ans[mid]!=ans[mid+1]){
                if(ans[mid]>ans[mid+1]){
                    ans[mid+1] = ans[mid];
                }
                else{
                    ans[mid]++;
                    ans[mid+1]=ans[mid];
                }
                return ans;
            }
            else if(!inc || same){
                if(ans[mid]==9){
                    while(l>=0 && r<n && ans[l]==9 && ans[r]==9){
                        ans[l]=0;
                        ans[r]=0;
                        l--;
                        r++;
                    }
                    if(l>=0 && r<n){
                        ans[l]++;
                        ans[r]++;
                    }
                }
                else{
                    ans[mid]++;
                    ans[mid+1]++;
                    return ans;
                }
            }
        }
        
        
        return ans;
    }
};