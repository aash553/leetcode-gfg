class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If opening bracket, push onto stack
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // If closing bracket and stack is empty, invalid
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check if the current closing bracket matches the last opening
                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // After processing all characters, stack should be empty if valid
        return st.empty();
    }
};
