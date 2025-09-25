class Solution {
public:
    vector<vector<int>>t;
    int solve(int i , int j , string &word1, string &word2){
    //base case 
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(t[i][j] != -1) return t[i][j]; 
    if(word1[i] == word2[j]){
        return t[i][j] =  solve(i-1,j-1,word1,word2);
    }else{
        return t[i][j] = 1+ min({
            solve(i,j-1,word1,word2),
            solve(i-1,j,word1,word2) ,
            solve(i-1,j-1,word1,word2)
        });
    }
    }


    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        t.assign(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,word1,word2);
    }
};