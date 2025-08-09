// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
       priority_queue<int>maxHeap;
       for(auto it : arr){
           maxHeap.push(it);
       }
       
       while(maxHeap.size()>k){
           maxHeap.pop();
       }
       return maxHeap.top();
    }
};