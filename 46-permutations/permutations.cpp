class Solution {
public:
    void permutations(int ind, vector<int>& nums, vector<vector<int>> &ans, int n){
        //base case
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        for(int i =ind ;i<n;i++){
            swap(nums[ind],nums[i]);
            permutations(ind + 1, nums,ans,n);
            //backtrack to get the original
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        permutations(0,nums,ans,n);
        return ans;
    }
};