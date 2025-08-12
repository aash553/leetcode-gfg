class Solution {
  public:
  
  
  
  int sorty(vector<int> &arr , int s , int e){
      int inv =0;
      int mid = s+(e-s)/2;
      int len1 = mid -s +1;
      int len2 = e -mid;
      
      int * first = new int[len1];
      int * second = new int[len2];
      
      int main = s;
      for(int i =0;i<len1;i++){
          first[i] = arr[main++];
      }
      main = mid+1;
      for(int i =0;i<len2 ; i++){
          second[i] = arr[main++];
      }
      
      int index1=0;
      int index2 =0;
      main = s;
      
      while(index1<len1 && index2< len2){
          if(first[index1] <= second[index2]){
              arr[main++] = first[index1++];
          }else{
              arr[main++] = second[index2++];
              inv += (len1-index1);
          }
      }
      while(index1 < len1){
          arr[main++] = first[index1++ ]; 
      }
      while(index2 < len2){
          arr[main++] = second[index2++];
      }
      return inv;
  }
  
  
  int mergesort(vector<int> &arr , int s , int e){
      int inv = 0;
      if(s<e){
      int mid = s+(e-s)/2;
      inv += mergesort(arr,s,mid);
      inv += mergesort(arr,mid+1,e);
      inv += sorty(arr,s,e);
      }
      return inv;
  }
    int inversionCount(vector<int> &arr) {
        return mergesort(arr,0,arr.size()-1);
    }
};