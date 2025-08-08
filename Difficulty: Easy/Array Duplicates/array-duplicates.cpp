class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>res;
        for(int i =0;i<n;i++){
        int index = abs(arr[i])-1;
            if(arr[index]<0){
                res.push_back(abs(arr[i]));
            }
            else{
            arr[index] *= -1;
            }
        }
        return res;
    }
};