class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        int n = s.length();
        int l=0;
        int mx=0;
        vector<int>frq(26,0);
        
        for(int r=0; r<n;r++){
            
            frq[s[r]-'a']++;
            
            while(frq[s[r]-'a']>1){
                frq[s[l]-'a']--;
                l++;
            }
            
            mx  = max(mx, r-l+1);
        }
        return mx;
    }
};