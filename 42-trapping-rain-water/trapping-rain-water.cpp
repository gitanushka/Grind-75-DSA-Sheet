class Solution {
public:
    int trap(vector<int>& height) {
        //optimal solution using two pointer approach
        int size = height.size();
        //left or right 2 pointer rakh liye 
        int l = 0, r = size - 1;
        //max building jo left me aayegi or max building jo right me aaye
        int leftmax = 0, rightmax = 0;
        //resultant water jo chahiye hame
        int res = 0;
        //jb tk left pointer ka index chota ya barabar h right pointr ke index se
        while(l<=r){
            //agr meri height jo left pe aarui hai vo choti hai right ke
            if(height[l]<=height[r]){
                //or agr meri building badi h leftmax se to leftmax ko update krdo
                if(height[l]>leftmax) leftmax = height[l];
                //agr nhi h iska mtlb ki left max se choti h to udhr water store hua hai to kitna hua h hamari jo max left building hai minus meri jo current building h vo
                else res += leftmax - height[l];
            l++;    
            }
            //else mtlb jo right me building h vo choti h left ki building se
            else{
                //agr right meri jo current building h vo badi h rightmax se to rightmax ko update krdo
                if(height[r]>rightmax) rightmax = height[r];
                //badi nhi h mtlb water store ho skta h to add up krlo 
                else res += rightmax - height[r];
            r--;    
            }
        }
        return res;
    }
};