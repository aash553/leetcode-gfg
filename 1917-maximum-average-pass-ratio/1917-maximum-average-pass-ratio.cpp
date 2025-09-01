class Solution {
public:

    using P = pair<double, int>;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq;


        for(int i =0;i<n;i++){
            double curr_pr = (double)classes[i][0]/classes[i][1];
            double new_pr = (double)(classes[i][0] + 1) / (classes[i][1] +1);
            double improve = (double)new_pr - curr_pr;
            pq.push({improve,i});
        }
        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            double index = curr.second;

            classes[index][0]++;
            classes[index][1]++;

            //this is for the second iteration 
            //we also need to notice that the value for other havent changed so we just need to 
            //change for the one we added the value 
            double curr_pr = (double)classes[index][0]/classes[index][1];
            double new_pr = (double)(classes[index][0] + 1) / (classes[index][1] +1);
            double improve = (double)new_pr - curr_pr;
            pq.push({improve,index});

        }

            double result = 0;
            for(int i=0;i<n;i++){
                result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};