class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxarea = INT_MIN;

        for(int i =0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int height = heights[st.top()]; 
                st.pop();
                int nse  = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(height*(nse-pse-1),maxarea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(height*(nse-pse-1),maxarea);
        }

        return maxarea;
    }
};