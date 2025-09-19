class Solution {
  public:
    int minParentheses(string& s) {
        int open = 0;
        int close = 0;
        for(char cha : s){
            if(cha=='('){
                open++;
            } else if(cha ==')'){
                if(open>0){
                    open--;
                } else{
                    close++;
                }
            }
        }
        return open+close;
    }
};