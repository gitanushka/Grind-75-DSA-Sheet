class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if(intervals.size()<=1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> tempinterval = intervals[0];
        for(auto it: intervals){
            if(it[0]<=tempinterval[1]){
                //case of merging
                tempinterval[1] = max(it[1],tempinterval[1]);
            }
            else{
                ans.push_back(tempinterval);
                tempinterval = it;
            }
        }
        ans.push_back(tempinterval);
        return ans;
    }
};