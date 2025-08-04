class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxi = INT_MIN;
        for(int i =0;i<n ;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int height = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(height*(nse-pse-1),maxi);
            }
            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxi = max(height * (nse-pse-1),maxi);
        }
        return maxi;
    }
};