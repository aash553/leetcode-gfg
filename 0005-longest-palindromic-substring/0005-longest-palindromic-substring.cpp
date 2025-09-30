class Solution {
public:
    bool ispalindrome(string &s, int left , int right){
        while(left < right ){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s , int i , int j , int &maxlen , int &start){
        //base case 
        int n = s.length();
        if(i==n) return;

        if(j<n){
            if(ispalindrome(s,i,j) && j-i+1 > maxlen){
                maxlen = j-i+1;
                start = i;
            }
            solve(s,i,j+1,maxlen,start);
        }
        else{
            solve(s,i+1,i+1,maxlen,start);
        }
    }
    string longestPalindrome(string s) {
        int start = 0;
        int n = s.length();
        int maxlen = 1;
        solve(s,0,0,maxlen,start);
        return s.substr(start , maxlen);
    }
};