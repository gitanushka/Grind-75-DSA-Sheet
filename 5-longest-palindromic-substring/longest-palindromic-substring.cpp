class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0,end = 1;
        int low,high;

        // if(s.length()<=1) return s;
        

        for(int i = 0 ; i < s.length() ; i++){
            //odd part
            low = i;
            high = i;

            while(low>=0 && high<s.length() && s[high]==s[low]){
                if(high-low+1 > end){
                    end = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
            //even part
            low  = i;
            high = i + 1;

            while(low>=0 && high<s.length() && s[high]==s[low]){
                if(high-low+1 > end){
                    end = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
        }
        return s.substr(start,end);
    }
};