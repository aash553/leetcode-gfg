class Solution {
public:
    string smallestSubsequence(string s) {
         int n = s.length();
        vector<int>lastindex(26);
        vector<bool>taken(26,false);

        string result;

        for(int i =0;i<n;i++){
            char ch = s[i];

            lastindex[ch-'a'] =i;
        }

        for(int i =0;i<n;i++){
            char ch = s[i];
            int idx =ch-'a';

            if(taken[idx]==true) continue;

            while(result.length()>0 && result.back() > ch && lastindex[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[idx] = true;
        }
        return result;
    }
};