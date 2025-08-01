#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Distribute N candies among K people
// Approach: Use a round-robin distribution method to ensure fair distribution of candies

// Steps:
// 1. Start with the first person and give them one candy.
// 2. Move to the next person and give them two candies, and so on.
// 3. Continue this process until you run out of candies.
// 4. If the candies left are less than the number of candies to be given to the current person, give them all the remaining candies.
// 5. Store the number of candies each person receives in a vector.
// 6. Return the vector containing the count of candies for each person.

// Time Complexity: O(N), where N is the total number of candies, as we iterate through the candies and distribute them.
// Space Complexity: O(K), for storing the count of candies for each person.

class Solution {
  public:
    vector<long long> distributeCandies(int N, int K) {
        int candies=N;
        vector<long long>ans(K+1,0);
        int last=1;
        while(candies)
        {
           for(int i=1;i<=K;i++)
           {
               if(candies<last)
               {
                   ans[i]+=candies;
                   ans.erase(ans.begin());
                   return ans;
               }
               else
               {
                   ans[i]+=last;
                   candies-=last;
                   last++;
               }
           }
        }
        ans.erase(ans.begin());
        return ans;
    }
};