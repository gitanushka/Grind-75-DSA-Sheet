class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid<=high){
            //3 case exist here if mid 0 , mid 1 or mid 2 
            switch(nums[mid]){
                //0 shifted to the lowest index and incrementing both indices
                case 0: swap(nums[low++],nums[mid++]); break;
                //1 nothing change since its 1 just increasing index of mid
                case 1: mid++; break;
                //2 shift to the highest index and decreamenting the index of high
                case 2: swap(nums[mid],nums[high--]); break;
            }
        }
    }
};