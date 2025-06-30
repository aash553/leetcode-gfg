class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int depth=0;
        for(char ch :s){
            if(ch =='('){
                depth++;
                maxi = (maxi,depth);
            }
            else if(ch == ')'){
                depth--;
            }
        }
        return maxi;
    }
};