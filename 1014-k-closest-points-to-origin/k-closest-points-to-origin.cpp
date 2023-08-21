class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<int,vector<int>>> maxH;

        for(int i=0;i<points.size();i++){
        maxH.push({points[i][0]*points[i][0] + points[i][1]*points[i][1],{points[i][0],points[i][1]}});
    
           if(maxH.size()>k){
               maxH.pop();
           }
        }
        vector<vector<int>> ans;

        while(maxH.size()>0){
            ans.push_back({maxH.top().second});
            maxH.pop();
        }
        return ans;
    }
};