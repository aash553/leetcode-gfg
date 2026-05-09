class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector<int>add;
        long long ans = 1;
        add.push_back(1);
        for(int i = 1;i<n;i++){
            ans = ans * (n-i);
            ans = ans/i;
            add.push_back(ans);
        }
        return add;
    }
};