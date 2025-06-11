class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // find the min and max  element 
        int n = nums.size();
        if ( n<2) return 0;

        int mini = nums[0];
        int maxi = nums[0];

        for (int i =0;i<n;i++){
            if(nums[i]<mini) mini = nums[i];
            if(nums[i]>maxi) maxi = nums[i];
        }
        if (mini==maxi) return 0;

        //get the bucketsize adn bucketcount (remeber always n-1 size for n-2 elements)

        int bucketsize = (maxi - mini + (n-2))/(n-1);
        int bucketcount = (maxi - mini)/bucketsize+1;

    //create the vectors to fill in 

    vector<int> bucketmin(bucketcount , INT_MAX);
    vector<int> bucketmax(bucketcount , INT_MIN);
    vector<bool> bucketused(bucketcount , false);

    //start filling the elements

    for(int i =0;i<n;i++){
        int num= nums[i];
        int ind = (num-mini)/bucketsize;

        if(!bucketused[ind]){
            bucketmin[ind]=num;
            bucketmax[ind]=num;
            bucketused[ind]=true;   
        }else{
            if(num<bucketmin[ind])bucketmin[ind] = num;
            if(num>bucketmax[ind]) bucketmax[ind] = num;
        }
    }

    //compute maxi gap now 

    int maxgap =0;
    int prev= mini;

    for ( int i=0;i<bucketcount;i++){
        if(!bucketused[i])continue;

        int gap = bucketmin[i] - prev;
        if(gap>maxgap) maxgap = gap;

        prev = bucketmax[i];
    }
    return maxgap;
}
};