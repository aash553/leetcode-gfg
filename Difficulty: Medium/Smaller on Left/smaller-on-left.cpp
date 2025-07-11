class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>nse(n);
        
        for(int i =0;i<n;i++){
            
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=-1;
            }else{
                nse[i]=st.top();
            }
            st.push(arr[i]);
        }
        return nse;
    }
};