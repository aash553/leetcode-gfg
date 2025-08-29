class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        for(int i =0;i<=m;i++){
            for(int j= 0;j<=n;j++){
                if(i==0 || j ==0){
                    t[i][j]= 0;
                }
            }
        }

        for(int i =1;i<m+1;i++){
            for(int j =1;j<n+1;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j] = 1 +t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
                }
            }
        }

        int i = m , j= n;
        string ans = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(t[i][j-1] > t[i-1][j]){
                ans.push_back(str2[j-1]);
                j--;
            }
            else{
                ans.push_back(str1[i-1]);
                i--;
            }
        }
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};