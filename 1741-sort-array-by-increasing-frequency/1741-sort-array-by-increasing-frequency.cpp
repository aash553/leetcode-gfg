class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mpp;

        for(auto it : nums){
            mpp[it]++;
        }

        vector<pair<int,int>>freqarr;
        for(auto &p : mpp){
            freqarr.push_back({p.first,p.second});
        }

        sort(freqarr.begin(),freqarr.end() , [] (pair<int,int>&a , pair<int,int>&b){
            if(a.second==b.second)
            return a.first>b.first;
            return a.second < b.second;
        });
        vector<int>result;
        for(auto & p : freqarr){
            for(int i =0;i<p.second;i++){
                result.push_back(p.first);
            }
        }
        return result;
    }
};