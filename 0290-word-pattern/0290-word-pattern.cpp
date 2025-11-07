class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string>words;
        string temp = "";

        for(char c : s) {
            if(c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        words.push_back(temp);   // last word

        if(pattern.size() != words.size()) return false;
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;

        for(int i = 0;i<pattern.size();i++){

            char a = pattern[i];
            string b = words[i];
            if(mp1.count(a) && mp1[a]!=b) return false;
            if(mp2.count(b) && mp2[b]!=a) return false;

           mp1[a]=b;
           mp2[b]=a;
        }
        return true;
    }
};