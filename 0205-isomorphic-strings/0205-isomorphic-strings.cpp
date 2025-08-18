class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size() != t.size()) return false;
    //    unordered_map<char,char>mp1;
    //    unordered_map<char,char>mp2;

    int mapst[256] = {0};
    int mapts[256] = {0};
       for(int i =0;i<s.size();i++){

        char a = s[i];
        char b = t[i];

        if(mapst[a] != 0 && mapst[a] != b) return false; 
        if(mapts[b] != 0 && mapts[b] != a) return false;

        mapst[a] = b;
        mapts[b] = a;
       }
       return true;
    }
};