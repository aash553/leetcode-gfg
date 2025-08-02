class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        unordered_map<int,int>mp;
        int minele = INT_MAX;
        
        for (int &x : basket1){
            mp[x]++;
            minele = min(minele,x);
        }

        for(int &x : basket2){
            mp[x]--;
            minele = min(minele,x);
        }

        vector<int>finalist;
        for(auto &it : mp){
            int cost = it.first;
            int freq = it.second;

            if(freq==0){
                continue;
            }

            if(freq %2 !=0){
                return -1;
            }

            for(int i =1 ; i<=abs(freq)/2;i++){
                finalist.push_back(cost);
            }
        }

        sort(finalist.begin(),finalist.end());

        long long result = 0;
        for(int i =0;i<finalist.size()/2;i++){
            result += min(finalist[i],minele*2);
        }
        return result;
    }
};