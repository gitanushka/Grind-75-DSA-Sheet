class Solution {
public:

int BinarySearch(vector<int> nums,int start,int end,int target){
       
        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
}

    int search(vector<int>& nums, int target) {
        int i;
        int minInd = 0;
        int minEle = nums[0];
        int size = nums.size();

        if(size==0) return -1;

        for(i=1;i<size;i++){
            if(nums[i]<minEle){
                minEle = nums[i];
               minInd = i;
            }
              
        }

        int index1 = BinarySearch(nums, 0, minInd-1, target);
        int index2 = BinarySearch(nums, minInd, size-1, target);
        return (index2 != -1) ? index2 : index1;

    }
};