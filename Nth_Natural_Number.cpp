
class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        int rem = n%9;
        if(n==0) return 0;
        long long ans = findNth(n/9);
        return ans*10+rem;
    }
};