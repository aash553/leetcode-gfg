class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,int>>q;
        int time = 0;
    
        //puish into the queue
        for(int i =0;i<n;i++){
            q.push({i,tickets[i]});
        }

        while(!q.empty()){
            auto [ind,t] = q.front();q.pop();

            t--;
            time++;

            if(t>0){
                q.push({ind,t});
            }
        if(ind==k && t==0){
            break;
        }
        }
        return time;
    }
};