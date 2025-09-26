class Solution {
  public:
  
  vector<vector<int>>t;
  int solve(vector<int>&arr,int i , int j){
      int mini = INT_MAX;
      int n = arr.size();
      if(i >= j) return 0;
      if(t[i][j] != -1 ) return t[i][j];
      for(int k = i ; k<j ; k++){
          int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
          if(temp < mini)
          mini = temp;
      }
      return t[i][j] =  mini;
  }
  
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        t.assign(n+1,vector<int>(n+1,-1));
        return solve(arr,1,n-1);
    }
};