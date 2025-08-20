class Solution {
  public:
        int findparent(vector<int>&parent , int x){
            if(parent[x] == x) 
            return x;
            parent[x] = findparent(parent,parent[x]);
            return parent[x];
        }
        
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n = deadline.size();
        vector<pair<int,int>>jobs;
        
        for(int i =0;i<n;i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        
        //sorting 
        sort(jobs.begin(),jobs.end(),[] (auto &a, auto &b){
            return a.first>b.first;
        });
        
        //findind the maximm deadline to make the array of that size
        int maxdeadline = *max_element(deadline.begin(),deadline.end());
        
        vector<int>parent(maxdeadline+1);
        for(int i =0;i<=maxdeadline;i++){
            parent[i] = i;
        }
        
        int totalprofit = 0;
        int jobcnt = 0;
        
        for(auto job : jobs){
            int prof = job.first;
            int dead = job.second;
            
            int availableslot = findparent(parent,dead);
            if(availableslot>0){
                totalprofit += prof;
                jobcnt++;
                parent[availableslot] = availableslot-1;
            }
        }
        return {jobcnt, totalprofit};
    }
};