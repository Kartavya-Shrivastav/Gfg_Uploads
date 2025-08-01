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