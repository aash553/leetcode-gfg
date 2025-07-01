class Solution {
  public:
  
  void merge(vector<int>&arr, int s , int e){
      int mid = s+(e-s)/2;
      
      int len1 = mid-s+1;
      int len2= e-mid;
      
      int * first = new int[len1];
      int * second = new int[len2];
      
      int mainarray = s;
      
      for(int i =0;i<len1;i++){
          first[i]=arr[mainarray++];
      }
      
      mainarray = mid+1;
      
      for(int i=0 ; i<len2;i++){
          second[i]=arr[mainarray++];
      }
      
      int index1=0;
      int index2=0;
      mainarray =s;
      
      while(index1<len1 && index2<len2){
          if(first[index1]<second[index2]){
              arr[mainarray++]=first[index1++];
          }
          else{
              arr[mainarray++]=second[index2++];
          }
      }
      
      while(index1<len1){
          arr[mainarray++] = first[index1++];
      }
      
      while(index2<len2){
          arr[mainarray++]= second[index2++];
      }
      
  }
  
  
    void mergeSort(vector<int>& arr, int l, int r) {
        
        if(l>=r) return ;
        
        int mid = l+(r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r);
    }
};