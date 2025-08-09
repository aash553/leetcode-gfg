// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>maxheap;
        for(auto it : arr){
            maxheap.push(it);
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
       return maxheap.top();
    }
};