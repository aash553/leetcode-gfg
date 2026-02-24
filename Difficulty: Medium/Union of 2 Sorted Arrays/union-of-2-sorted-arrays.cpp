class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int i =0;
        int j =0;
        int n = a.size();
        int m = b.size();
        vector<int>ans;
        
        while(i<n && j<m){
          int value;
          
          if(a[i]<b[j]){
              value = a[i];
              i++;
          }
          else if(a[i]==b[j]){
              value = a[i];
              i++;
              j++;
          }
          else{
            value = b[j];
              j++;
          }
          
          if(ans.empty() || ans.back() != value ){
              ans.push_back(value);
          }
        }
          
        while(i<n){
           int value = a[i];
           if(ans.empty() || ans.back() != value ){
              ans.push_back(value);
          }
            i++;
        }
        while(j<m){
          int  value = b[j];
           if(ans.empty() || ans.back() != value ){
              ans.push_back(value);
          }
            j++;
        }
            
            return ans;
        }
        
};