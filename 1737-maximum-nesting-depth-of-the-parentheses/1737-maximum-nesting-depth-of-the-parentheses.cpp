class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int maxi = 0;
        int depth = 0;
        for ( int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
                maxi = max(depth ,maxi);
            }
            else if(s[i]==')'){
                depth--;
            }
            }
            return maxi;
        }
};