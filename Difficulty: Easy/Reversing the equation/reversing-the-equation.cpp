class Solution {
  public:
    string reverseEqn(string s) {
        // code here.
        
        string result = "";
        string temp = "";
        
        for ( int i = s.length()-1;i>=0;i--){
            if(isdigit(s[i])){
                temp= s[i]+temp;
            }else{
                result+=temp;
                result+=s[i];
                temp= "";
            }
        }
        result+=temp;
        return result;
    }
};


// this is using the stack operation as well 

class Solution {
public:
    string reverseEqn(string s) {
        stack<string> st;
        string temp = "";

        // Traverse from left to right
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                temp += s[i]; // accumulate digits
            } else {
                st.push(temp);                   // push number
                st.push(string(1, s[i]));        // push operator as string
                temp = "";
            }
        }

        // Push the last number to the stack
        st.push(temp);

        // Build the result from stack (reverses the expression)
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
