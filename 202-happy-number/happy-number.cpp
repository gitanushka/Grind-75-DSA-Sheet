class Solution {
public:
    bool isHappy(int n) {
       
        unordered_set<int> s;

        while(s.count(n)==0){
            if(n==1) return true;
          s.insert(n);
           int sum = 0;  
          while(n){
          sum += (n%10)*(n%10);
          n /=10; 
        }
          n = sum;
      }
        return false;
    }
};