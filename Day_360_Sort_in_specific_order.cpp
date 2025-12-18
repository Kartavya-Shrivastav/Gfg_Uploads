class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(), [](int &a, int &b){
            if(a%2==b%2 && a%2==0)return a<b;
            else if(a%2==b%2 && a%2==1)return a>b;
            return a%2==1;
        });
    }
};