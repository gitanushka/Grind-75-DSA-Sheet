class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int minn = INT_MAX - 1000, maxx = INT_MIN + 1000;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<(n-2); i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                else if(sum > target){
                    minn = min(minn, sum);
                    k--; 
                }
                else if(sum < target){
                    maxx = max(maxx, sum);
                    j++;
                }
            }
        }
        int a = minn - target;
        int b = target - maxx;

        if(a < b) return minn;
        else return maxx;
    }
};