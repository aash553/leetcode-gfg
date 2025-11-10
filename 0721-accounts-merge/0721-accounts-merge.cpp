class disjoint {
public:
    vector<int> parent, rankv;

    disjoint(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void Union(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(rankv[ulp_u] < rankv[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } 
        else if(rankv[ulp_v] < rankv[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rankv[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        disjoint ds(n);

        unordered_map<string, int> mailToNode;

        // Step 1: Map each mail to its account + union accounts sharing same mail
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                } 
                else {
                    ds.Union(i, mailToNode[mail]);
                }
            }
        }

        // Step 2: Group emails by the ultimate parent (root) of each account
        vector<vector<string>> merged(n);

        for(auto it : mailToNode) {
            string mail = it.first;
            int accIndex = it.second;

            int parent = ds.findUpar(accIndex);
            merged[parent].push_back(mail);
        }

        // Step 3: Build final answer
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(merged[i].size() == 0) continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &mail : merged[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
