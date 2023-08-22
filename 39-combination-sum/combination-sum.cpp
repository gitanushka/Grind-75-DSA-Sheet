class Solution {
public:
    void combination(int ind, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &ds){
        //base case
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //pick element
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            combination(ind,candidates,target-candidates[ind],ans,ds);
            //pop element from ds when no combination found in the left call
            ds.pop_back();
        }
        //right call of recursion with next index  
        combination(ind+1,candidates,target,ans,ds);
    }
public:    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        combination(0, candidates, target, ans, ds);
        return ans;
    }
};