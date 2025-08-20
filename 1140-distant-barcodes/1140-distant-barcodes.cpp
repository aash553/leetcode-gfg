class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        map<int,int>freq;

        for(auto x : barcodes){
            freq[x]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto it : freq){
            pq.push({it.second,it.first});
        }

        vector<int>result;

        while(!pq.empty()){
            auto first = pq.top(); pq.pop();
            if(result.empty() || result.back() != first.second){
                result.push_back(first.second);
                first.first--;
            }else{
                auto second = pq.top(); pq.pop();
                result.push_back(second.second);
                second.first--;
                //once second is pushed we push first again
                pq.push(first);

                if(second.first>0)pq.push(second);
                continue;
            }
                if(first.first>0) pq.push(first);
        }
        return result;
    }
};