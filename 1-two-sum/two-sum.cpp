class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int dig = target - num;
            if(mp.find(dig)!=mp.end()){
                return {mp[dig],i};
            }
            mp[num] = i;
        }
        return {}; 
    }
    
  
};
