class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int M = 1e9+7;
        stack<int>st;
        int n = arr.size();
         vector<int> pse(n), nse(n);

        for(int i =n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]= st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long  total = 0;
        
        for(int i=0;i<n;i++){
            long long  left = i-pse[i];
            long long  right = nse[i]-i;

            total = (total+(right*left*1LL*arr[i])%M)%M;
        }
        return total;
    }
};