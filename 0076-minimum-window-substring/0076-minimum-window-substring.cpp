class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length();
        if(t.length() > s.length()) return "";

        int minwindow = INT_MAX;
        int requiredcount = t.length();
        int i =0 , j=0;
        int start_i=0;

        map<char,int>mpp;
       for(char &ch : t){
        mpp[ch]++;
       }
        while(j<n){
            char ch = s[j];

            if(mpp[ch]>0){
                requiredcount--;
            }
            mpp[ch]--;

            while(requiredcount==0){
                //start shrinking the window
                int currwindow = j-i+1;
                if(minwindow>currwindow){
                minwindow = currwindow;
                start_i = i;
                }
                mpp[s[i]]++; 
                if(mpp[s[i]]>0){
                    requiredcount++;
                }
                i++;
            }
            j++;
        }
        return minwindow == INT_MAX ? "" : s.substr(start_i,minwindow);
    }
};