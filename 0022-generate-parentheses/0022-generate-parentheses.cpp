class Solution {
public:

    void func(int start ,int end , int n ,vector<string>&ans, string curr_str){
        if(curr_str.size() == n*2){
            ans.push_back(curr_str);
            return;
        }

        if(start<n)func(start+1,end,n,ans,curr_str+"(");
        if(end<start)func(start,end+1,n,ans,curr_str+")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        func(0,0,n,ans,"");
        return ans;
    }
};