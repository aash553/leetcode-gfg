class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n = num1.size();
        int m = num2.size();

        vector<int>res(n+m,0);

        for(int i =n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j >=0 ;j--){
                int mul = (num1[i]-'0') * ( num2[j]-'0');
                int sum = mul + res[i+j+1];

                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }

        string ans = "" ;
        for(int num : res){
            if(ans.empty() && num==0) continue;
            ans += (num+'0');
        }
        return ans.empty() ? "0" : ans;
    }
};