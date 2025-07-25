class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int>result;
        
        if(s.length()<p.length()) return {};

        vector<int>freq1(26,0) , freq2(26,0);

        for(int i =0;i<p.size();i++){

            freq1[s[i]-'a']++;
            freq2[p[i]-'a']++;
        } 
        if(freq1==freq2) result.push_back(0);
        for(int i =p.length();i<s.length();i++){

            freq1[s[i]-'a']++;
            freq1[s[i-p.length()]-'a']--;
            if(freq1==freq2) result.push_back(i-p.length()+1);
        }
        return result;
    }
};