class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int i=0,j=0, mx = 0;


        while(j<s.length()){
            if(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            else if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
                mx = max(mx,j-i);
            }
        }
        return mx;

    }
};