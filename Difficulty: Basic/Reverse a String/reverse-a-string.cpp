// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        int start=0;
         int end = s.length()-1;
         while(start<end){
         char temp = s[start];
         s[start]= s[end];
         s[end]=temp;
         start++;
         end--;
         }
         return s;
    }
};
