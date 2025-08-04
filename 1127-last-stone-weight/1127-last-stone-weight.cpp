class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        //pushing all elements of array in to maxheap
        int n = stones.size();
        priority_queue<int>q;
        for(auto it : stones){
            q.push(it);
        }
        while(q.size()>1){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();

            if(x!=y){
                y=abs(y-x);
                q.push(y);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};