class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int mxl[size],mxr[size];

        mxl[0] = height[0];
        for(int i=1;i<size;i++){
            mxl[i] = max(mxl[i-1],height[i]);
        }

        mxr[size-1] = height[size-1];
        for(int i = size-2;i>=0;i--){
            mxr[i] = max(mxr[i+1],height[i]);
        }

        int water[size];
        for(int i = 0; i<size ;i++){
            water[i] = min(mxl[i],mxr[i]) - height[i];
        }
        int sum = 0;
        for(int i=0 ;i<size ;i++){
            sum += water[i];
        }
        return sum;
    }
};