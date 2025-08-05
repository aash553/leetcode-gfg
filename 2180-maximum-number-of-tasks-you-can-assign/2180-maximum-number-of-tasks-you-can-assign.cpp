class Solution {
public:

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength , int mid){
        int pillsused = 0;
        multiset<int> st(workers.end() - mid, workers.end()); // this is for the best owrkers till mid;

        for(int i = mid -1 ;i>=0 ;i--){
            int req = tasks[i];
            auto it = prev(st.end());
        if(*it >= req){
            st.erase(it);
        }else if (pillsused >= pills){
            return false;
        }else{
            auto weakest = st.lower_bound(req-strength);
            if(weakest == st.end()){
                return false;
            }
            st.erase(weakest);
            pillsused++;
        }
        }
        return true;
    }



    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        int  l = 0 ;
        int  r = min(m,n);

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(), workers.end());


        int result = 0;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(check(tasks,workers,pills,strength,mid)){
                result = mid;
                l=mid+1;
            }else{
                r = mid -1;
            }
        }
        return result;
    }
};