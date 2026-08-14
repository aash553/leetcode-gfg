class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int i =-1;
        for(int l = 0;l<n;l++){
            if(arr[l] == 0){
                i = l;
                break;
            }
        }
        if(i ==-1) return ;
        for(int j =i+1;j<n;j++){
            if(arr[j] == 0){
            // do nothing as we are already incrementing j in the for loop
            }
            else{
                swap(arr[i],arr[j]);
                i++;
                //here also its the same
            }
        }
    }
};