class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>>meeting;
        for(int i =0;i<n;i++){
            meeting.push_back({end[i],start[i]});
        }
        
        sort(meeting.begin(),meeting.end());
        
        int count = 1;
        int ended = meeting[0].first;
        
        for(int i = 1 ;i<meeting.size();i++){
            if(meeting[i].second > ended){
                count++;
                ended = meeting[i].first;
            }
        }
        return count;
    }
};