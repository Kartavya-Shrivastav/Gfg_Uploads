
class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
          int n=s.length(), ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ans+=(stoi(s.substr(i, j-i+1)));
            }
        }
        return ans;
    }
};