class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for(auto it : intervals) {
            while(!pq.empty() && pq.top() <= it[0]) {
                pq.pop();
            }
            pq.push(it[1]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};