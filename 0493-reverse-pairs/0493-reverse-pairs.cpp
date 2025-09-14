class Solution {
public:

    void merge(vector<int>&nums , int low , int mid , int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;
        int cnt = 0;
        while(left<= mid && right <=high){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;

                }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i<=high ;i++){
            nums[i] = temp[i-low];
        }
    }

    int countpair(vector<int>&nums , int low, int mid ,int high){
        int cnt = 0;
        int right = mid + 1;
        for(int i =low ;i<=mid ;i++){
            while(right <= high && (long long) nums[i] > 2LL * nums[right]){
                right ++ ;
            }
                cnt += (right - (mid +1));
        }
        return cnt;
    }

   int mergesort(vector<int>&nums , int low, int high){
    //base case 
    if(low >= high) return 0;
    int mid = low+(high-low)/2;
    int cnt = 0;
    cnt += mergesort(nums,low,mid);
    cnt += mergesort(nums,mid+1,high);
    cnt += countpair(nums,low,mid,high);
    merge(nums,low,mid,high);
    return cnt ;
   }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
};