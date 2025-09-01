class Solution {
public:

 vector<vector<int>>t;
    int solve(int k , int n){
    if(n==0 || n== 1) return n;
    if(k == 1 ) return n;

    if(t[k][n] != -1) return t[k][n];
    int mini = INT_MAX;
    int low =1 , high =n ;
    while(low<=high){
        int mid = low+(high-low)/2;
        int left = solve(k-1,mid-1);
        int right = solve(k,n-mid);
        int temp = 1+max(left,right);
        mini = min(mini,temp);

        if(left<right){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return t[k][n] =  mini;
    }

    int superEggDrop(int k, int n) {
    t.assign(k+1, vector<int>(n+1, -1));
    return solve(k,n);

    }
};