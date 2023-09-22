class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> ans;
        int i=1,j=numbers.size();
           while(i<j){
               if(numbers[i-1]+numbers[j-1]==target){
                   ans.push_back(i);
                   ans.push_back(j);
                   break;
               }
               else if(numbers[i-1]+numbers[j-1]<target){
                   i++;
               }
               else{
                   j--;
               }
           }
           return ans;
    }
};