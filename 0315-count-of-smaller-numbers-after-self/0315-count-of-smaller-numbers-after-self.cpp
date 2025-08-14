class Solution {
public:


    void merge(vector<pair<int,int>>&arr , int s, int mid, int e , vector<int>&count){
        vector<pair<int,int>> temp;
        int i = s;
        int j = mid+1;
        int rightcount = 0;

        while(i<=mid && j<=e){
            if(arr[i].first <= arr[j].first){
                count[arr[i].second]+= rightcount;
                temp.push_back(arr[i]);
                i++;
            }else{
                 rightcount++;
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            count[arr[i].second] += rightcount;
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= e) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = s; k <= e; k++) {
            arr[k] = temp[k - s];
        }
    }

    void mergresort(vector<pair<int,int>>&arr , int s, int e , vector<int>&count){

        if(s>=e) return ;

        int mid = s+(e-s)/2;
        mergresort(arr,s,mid,count);
        mergresort(arr,mid+1,e,count);
        merge(arr,s,mid,e,count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<int>count(nums.size(), 0);
        vector<pair<int,int>> arr; // value , index
        
        for(int i =0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }

        mergresort(arr,0,nums.size()-1 , count);
        return count;
    }


};