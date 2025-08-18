class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int maxi =0;
        for(int i =0;i<s.length();i++){
            if(s[i]=='('){
                maxdepth++;
                maxi = max(maxi,maxdepth);
            }
            else if (s[i] == ')'){
                maxdepth--;
            }
        }
        return maxi;
    }
};