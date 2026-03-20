class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n1=s.size();
        int n2=p.size();
        if(n2>n1)return "";
        
        vector<bool>v(26,0); // use to check char is in p or not
        vector<int>count1(26,0);// help us to determine all char present in substring or not
        vector<int>count2(26,0);// number of each char in p
        
        for(int i=0;i<p.size();i++){
           v[p[i]-'a']=1;
           count1[p[i]-'a']++;
           count2[p[i]-'a']++;
        }
        
        int a=0,b=0;
        int start=0;
        int end=-1;
        int ans=INT_MAX;
        int k = 0; // how many char till present in substring
        
        
        while(end<n1){
            
            if(k==n2){ // all char present update ans.
                
                int size = end-start+1;
                if(size<ans){
                    a=start;
                    b=end;
                    ans=size;
                }
                
                if(v[s[start]-'a']){ // remove first char of substring
                    
                    count1[s[start]-'a']++;
                    int temp = count2[s[start]-'a']-count1[s[start]-'a'];// count of start index char present in substring
                    if(temp<count2[s[start]-'a'])k--;
                       
                }
                
                start++;
                
            }
            else{ // increase the lenght and check
                
                end++;
                if(end>=n1)break;
                
                if(v[s[end]-'a']){
                    
                    if(count1[s[end]-'a']>0){ // help for duplication
                        count1[s[end]-'a']--;
                        k++;
                    }
                    else count1[s[end]-'a']--;
                }
                
            }
        }
        
        if(ans==INT_MAX)return "";
        
        return s.substr(a,b-a+1);
        
        
    }
};