class Solution {
public:
    int maxArea(vector<int>& height) {
        //left pointer le liya 0 pe
        int left = 0;
        //right pointer le liya height vector ke size - 1 pe
        int right = height.size()-1;
        //maz area ke lye maxi le liya
        int maxi = 0;

        while(left<right){
            //width canculate ki joki right pointer minus left hogi 
            int w = right  - left;
            //height calculate ki joki ham  in height lege dpno me se taaki water overflow na ho 
            int h = min(height[left],height[right]);
            //area nikalenge
            int area = w * h;
            //maxi max area ko store krta rhega
            maxi = max(maxi,area);
            //agr left wale ki height km hui to left wale ko aage badhayenge
            if(height[left]<height[right]) left++;
            //agr right wale ki choti hui to usko piche lenge
            else if(height[left]>height[right]) right--;
            //dono ki same hui toh
            else{
                left++;
                right--;
            }
        }
        return maxi;
    }
};