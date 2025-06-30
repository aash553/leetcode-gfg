class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int depth=0;
        for(int i =0;i<s.length();i++){
            if(s[i] =='('){
                depth++;
                maxi = max(maxi,depth);
            }
            else if(s[i] == ')'){
                depth--;
            }
        }
        return maxi;
    }
};