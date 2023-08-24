class Solution {
public:
    vector<vector<int>> ans;

    void sub(int i, vector<int>& nums, vector<int> temp){
        //base case
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }

        sub(i+1,nums,temp);
        temp.push_back(nums[i]);
        sub(i+1,nums,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        sub(0,nums,temp);
        return ans;
    }
};