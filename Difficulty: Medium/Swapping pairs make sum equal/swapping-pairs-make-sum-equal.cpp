class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        int cnta=0,  cntb=0;
        for(int i =0;i<a.size();i++){
            cnta+=a[i];
        }
        
        for(int i=0;i<b.size();i++){
            cntb+=b[i];
        }
        
        int diff = cnta-cntb;
        
        if(diff%2!=0)return false;
        
        int target = diff/2;
        
        unordered_set<int>setb(b.begin(),b.end());
        
        for(int i =0;i<a.size();i++){
            int need = a[i]-target;
            
            
            if(setb.count(need)){
                return true;
            }
        }
        return false;
    }
};