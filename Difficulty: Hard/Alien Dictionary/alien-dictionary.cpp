class Solution {
  public:
  
  
  vector<int>topo(int V, vector<int>adj[]){
      vector<int>indegree(V,0);
      for(int i =0;i<V;i++){
          for(auto it : adj[i]){
              indegree[it]++;
          }
      }
      
      queue<int>q;
      for(int i =0;i<V;i++){
          if(indegree[i] == 0){
              q.push(i);
          }
      }
      
      vector<int>topo;
      while(!q.empty()){
          int node = q.front();
          q.pop();
          topo.push_back(node);
          
          for(auto actualnode : adj[node]){
              indegree[actualnode]--;
              if(indegree[actualnode] == 0){
                  q.push(actualnode);
              }
          }
      }
      return topo;
  }
  
  
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        unordered_set<char>st;
        for(auto &w : words){
            for( char c : w){
                st.insert(c);
            }
        }
        int k = st.size();
        
    vector<int>adj[26];
    for(int i = 0 ;i<n-1;i++){
        string s1 = words[i];
        string s2 = words[i+1];
        int len = min(s1.size(),s2.size());
        
         if (s1.size() > s2.size() && s1.substr(0, len) == s2) {
                return "";
            }
            
        for(int ptr = 0 ; ptr<len ;ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }
   vector<int> order = topo(26, adj);

string ans;
for (int v : order) {
    char c = 'a' + v;
    if (st.count(c)) ans.push_back(c);
}
if ((int)ans.size() < k) return "";  // cycle among present letters
return ans;
}
};