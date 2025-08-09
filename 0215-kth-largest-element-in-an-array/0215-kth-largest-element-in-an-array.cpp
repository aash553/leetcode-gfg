class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //use of min heap 

        priority_queue<int, vector<int> ,greater<int>> minheap;

        for(auto it : nums){
            minheap.push(it);
        }

        while(minheap.size()>k){
            minheap.pop();
        }
        return minheap.top();
    }
};