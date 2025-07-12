class Solution {
public:

      int solve(char a){
            switch (a) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
             default : return 0;
        }
        }

    int romanToInt(string s) {
        int result = 0;
        int n = s.length();
        for(int i =0;i<n;i++){
            if(i+1<s.length() && solve(s[i])< solve(s[i+1]) ){
                result -= solve(s[i]);
            }
            else{
                result+=solve(s[i]);
            }
        }
        return result;
    }
};