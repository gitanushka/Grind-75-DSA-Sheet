class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26), freqS(26);

        for(auto it:p) freqP[it-'a']++;

        int low = 0;
        vector<int> ans;
        for(int high=0 ; high<s.length();high++){
            freqS[s[high]-'a']++;
            if(high-low+1==p.length() && freqP==freqS){
                ans.push_back(low);
            }

            if(high-low+1>=p.length()){
                freqS[s[low]-'a']--;
                low++;
            }
        }
        return ans;
    }
};