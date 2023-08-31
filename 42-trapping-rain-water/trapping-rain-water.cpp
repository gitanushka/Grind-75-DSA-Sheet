class Solution {
public:
    int trap(vector<int>& height) {
        //visulaize it with building nd follow the process
        int size = height.size();
        int mxl[size],mxr[size];
        
        mxl[0] = height[0];
        //left se chalu krt hue max left nikalenge har index ke liye taaki hame max building milti rhe
        for(int i=1;i<size;i++){
            mxl[i] = max(mxl[i-1],height[i]);
        }
        //right se chalu krte hue right max update krt rhenge 
        mxr[size-1] = height[size-1];
        for(int i = size-2;i>=0;i--){
            mxr[i] = max(mxr[i+1],height[i]);
        }
        // water kitna rhega? hamara jo max l or r aaye h unka min or minus krdenge us particular building ki height se utna hi store hoga
        int water[size];
        for(int i = 0; i<size ;i++){
            water[i] = min(mxl[i],mxr[i]) - height[i];
        }
        //sare water ka sum kr denge
        int sum = 0;
        for(int i=0 ;i<size ;i++){
            sum += water[i];
        }
        return sum;
    }
};