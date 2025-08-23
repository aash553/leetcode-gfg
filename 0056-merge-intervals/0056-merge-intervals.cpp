class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //brute force 
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i =0;i<n;i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        //if there exist an interval already
        if(!ans.empty() &&  end <= ans.back()[1]){
            continue;
        }
        for(int j = i+1 ;j<n;j++){
            if(intervals[j][0] <= end){
                end = max(intervals[j][1],end);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
        }
        return ans;
    }
};