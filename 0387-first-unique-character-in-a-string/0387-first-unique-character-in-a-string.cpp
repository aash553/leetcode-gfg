class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char,int>freq;
        int n = s.length();

          for (char c : s) {
            freq[c]++;
        }
        for(int i =0;i<n;i++){
            if(freq[s[i]] ==1 ){
                return i;
            }
        }
        return -1;
    }
};