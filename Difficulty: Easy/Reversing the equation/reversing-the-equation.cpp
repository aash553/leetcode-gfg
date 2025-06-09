class Solution {
  public:
    string reverseEqn(string s) {
        // code here.
        
        string result = "";
        string temp = "";
        
        for ( int i = s.length()-1;i>=0;i--){
            if(isdigit(s[i])){
                temp= s[i]+temp;
            }else{
                result+=temp;
                result+=s[i];
                temp= "";
            }
        }
        result+=temp;
        return result;
    }
};