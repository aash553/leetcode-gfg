class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long >cumsum(n+1,0);
        int result = INT_MAX;
        deque<int>deq;
        int j=0;
        while(j<n){
            if(j==0){
                cumsum[j]=nums[j];
            }else{
                cumsum[j] = cumsum[j-1]+nums[j];
            }

            if(cumsum[j]>=k){
                result =  min(result,j+1);
            }
            //need to shrink window 
            while(!deq.empty() && cumsum[j] - cumsum[deq.front()] >= k){
                result = min(result,j-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() && cumsum[j]<= cumsum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }
        return (result==INT_MAX) ? -1 : result;
    }
};