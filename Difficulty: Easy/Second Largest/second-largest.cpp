class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int prev = INT_MIN;
        int maxi = INT_MIN;
        for(int i = 0 ; i <n ;i++){
            if(arr[i] > maxi){
                prev = maxi;
                maxi = arr[i];
            }else if( arr[i] < maxi && arr[i] > prev){
                prev = arr[i];
            }
        }
        if(prev == INT_MIN) return -1;
        return prev;
    }
};