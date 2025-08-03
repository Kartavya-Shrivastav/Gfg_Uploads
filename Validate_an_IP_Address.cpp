class Solution {
  public:
    int isValid(string &s) {
        string t="";
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(i>0&&s[i]==s[i-1]&&s[i]=='.')return 0;
            else if(s[i]=='.')
            {
                cnt++;
                if(cnt>3)return 0;
                if(stoi(t)>255)return 0;
                if(stoi(t)!=0&&t[0]=='0')return 0;
                t="";
            }
            else t+=s[i];
        }
        if(stoi(t)>255)return 0;
        if(stoi(t)!=0&&t[0]=='0')return 0;
        return cnt==3;
    }
};