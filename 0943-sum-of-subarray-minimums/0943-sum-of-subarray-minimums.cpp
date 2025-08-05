class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int m = 1e9+7;
        int n = arr.size();
        stack<int>st;
        vector<int>nse(n),pse(n);

        for(int i =n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >=  arr[i]){
                st.pop();
            }
            nse[i] =  st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long sum = 0;
        for(int i =0;i<n;i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;

            sum = (sum+(right*left*1LL*arr[i])%m)%m;
        }
        return sum;
    }
};