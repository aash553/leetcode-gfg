class Solution {
  public:
    string multiplyStrings(string &s1, string &s2) {
        
        
        bool isneg = false;
        
        if(s1[0] == '-' && s2[0] != '-') isneg = true;
        else if(s1[0] != '-' && s2[0] == '-') isneg = true;
        
        if(s1[0] == '-')s1=s1.substr(1);
        if(s2[0] == '-')s2=s2.substr(1);
        
        int n = s1.length();
        int m = s2.length();
        
        vector<int>res(n+m,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1 ; j>=0 ;j--){
                int mul = (s1[i] - '0') * (s2[j]-'0');
                int sum = mul + res[i+j+1];
                
                res[i+j+1] = sum % 10 ;
                res[i+j] += sum/10;
            }
        }
        
        string ans = "";
        for (auto num : res){
            if(ans.empty() && num == 0) continue;
            ans += (num + '0');
        }
         if(ans.empty()) return  "0";
        if(isneg)  ans = '-' + ans;
        return ans;
        
    }
};