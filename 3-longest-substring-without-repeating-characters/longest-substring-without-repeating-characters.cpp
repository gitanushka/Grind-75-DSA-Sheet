class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,mx=0;
        unordered_set<char> st;
        while(j<s.length()){
            //unique character
            if(st.count(s[j])==0){
                st.insert(s[j]);
                mx = max(mx,j-i+1);
            }
            //duplicate character
            else {
                while(st.count(s[j])){
                   
                      st.erase(s[i]);
                    
                   i++;
                
            }
            st.insert(s[j]);
        }
        j++;
    } 
        return mx;
    }
};