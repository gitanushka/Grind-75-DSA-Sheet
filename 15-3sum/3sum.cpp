class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1, k= nums.size()-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};