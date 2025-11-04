class Solution {
  public:
  
  int merge(vector<int>&arr , int low , int high , int mid){
      int left = low;
      int right = mid+1;
      int cnt = 0 ;
      vector<int>temp;
      while(left <= mid && right <= high){
          if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
          }
          else{
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
            right++;
          }
      }
      while(left <= mid){
          temp.push_back(arr[left]);
          left++;
      }
      while(right <= high){
          temp.push_back(arr[right]);
          right++;
      }
      
      for(int i = low ; i <= high ; i++){
          arr[i] = temp[i-low];
      }
      return cnt;
  }
  
  int solve(vector<int>&arr, int low , int high){
      int cnt = 0;
      if(low >= high) return cnt;
      int mid = low +(high-low)/2;
      cnt += solve(arr,low,mid);
      cnt += solve(arr,mid+1,high);
      cnt += merge(arr,low,high,mid);
      return cnt;
  }
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n= arr.size();
        return solve(arr, 0 , n-1);
    }
};