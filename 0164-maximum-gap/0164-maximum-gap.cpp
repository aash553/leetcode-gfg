class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        //edge case very important
        if (nums.size() < 2) return 0;

        int mini = nums[0];
        int maxi = nums[0];

        //finding mini and maxi element

        for(int i = 0;i<n;i++){
           if(nums[i]<mini) mini = nums[i];
           if(nums[i]>maxi) maxi = nums[i];
        }

        //another very important edge case
        if (maxi == mini) return 0;

        //calculation the bucketsize and bucketcount 
        int bucketsize = ((maxi-mini)+(n-2))/(n-1);
        int bucketcount = (maxi-mini)/bucketsize+1;

        //create buckets 

        vector<int>bucketmin(bucketcount , INT_MAX);
        vector<int>bucketmax(bucketcount, INT_MIN);
        vector<bool> bucketused (bucketcount , false);


        //distribution of elements accordingly
        for(int i =0;i<n;i++){
            int num = nums[i];
            int ind = (num-mini)/bucketsize;

            if(!bucketused[ind]){
                bucketmin[ind]=num;
                bucketmax[ind]=num;
                bucketused[ind] = true;
            }else{
                if(num<bucketmin[ind]) bucketmin[ind] = num;
                if(num>bucketmax[ind]) bucketmax[ind] = num;
            }
        }

        //computing maximum gap

        int maxigap = 0;
        int prev = mini;

        for(int i =0;i<bucketcount ; i++){
            if(!bucketused[i]) continue;

            int gap = bucketmin[i] - prev;
           if(gap>maxigap ) maxigap = gap;

           prev = bucketmax[i];
         }
         return maxigap;
    }
};