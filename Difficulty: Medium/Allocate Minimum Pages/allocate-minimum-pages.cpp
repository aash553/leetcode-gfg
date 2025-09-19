class Solution
{
  public:
  
  
  int minpages(vector<int>&arr, int mid){
      int n = arr.size();
      int student = 1;
      int pagestudent = 0; 
      for(int i =0;i<n;i++){
          if(arr[i]+ pagestudent <= mid){
              pagestudent += arr[i];
          }else {
              student ++;
              pagestudent = arr[i];
          }
      }
      return student;
  }
  
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k>n) return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = 0;
        for(int i =0 ;i<n;i++){
            high += arr[i];
        }
        
        while(low <= high){
            int mid = low+(high-low)/2;
            int student = minpages(arr,mid);
            
            if(student > k){
                low = mid + 1;
            }
            else {
                high = mid - 1 ;
            }
        }
        return low;
    }
};