class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        int cnt1=0 , cnt2=0;
        for(int i =0;i<a.size();i++){
            cnt1 += a[i];
        }
        for(int i =0;i<b.size();i++){
            cnt2 +=b[i];
        }
        
        int diff = cnt1-cnt2;
        
        if(diff %2 !=0) return false;
        
        int target = diff/2;
        
        unordered_set<int> setb(b.begin(),b.end());
        
        for(int i =0;i<a.size();i++){
            int need = a[i]-target;
            
            if(setb.count(need)){
                return true;
            }
        }
        return false;
    }
};