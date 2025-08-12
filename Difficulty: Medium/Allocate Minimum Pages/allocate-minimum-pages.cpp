class Solution {
  public:
  
  int minpages(vector<int>&arr, int pages ){
      int student = 1;
      int pagestudent = 0;
      
      for(int i =0; i<arr.size();i++){
        if(pagestudent + arr[i] <= pages){
            pagestudent += arr[i];
        }else{
            student++;
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
        for(int i =0;i<arr.size();i++){
            high += arr[i];
        }
        
        while(low<=high){
            int mid = low +(high-low)/2;
            
            int students = minpages(arr,mid);
            if(students > k){
                low = mid + 1;
            }
            else{
                high = mid -1 ;
            }
        }
        return low;
    }
};