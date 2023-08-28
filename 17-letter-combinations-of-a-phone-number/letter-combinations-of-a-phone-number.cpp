class Solution {
public:
    void combinations(int num, vector<string> &ans, string output, string options[]) {
        //base case : agr no. divide hote hote 0 ban jaye tb ek combination ban jayega use push krdo
        if(num==0){
            ans.push_back(output);
            return;
        }
        // vo number ke last digit ko liya
        int last_dig = num%10;
        //us last digit ko as index pass krke uske corresponding letters ko liya
        string s = options[last_dig];
        //loop chalaya un letters ki length tk 
        for(int i=0;i<s.length();i++){
            //recusrsive call kiya of number ko tod te gye or jo letter h usko output me append kr diya combination banane ke liye
            combinations(num/10,ans, s[i]+output, options);
        }
    }
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
      string output = "";
      //phone no ke digits ke hisaab se sare letters array me store kr liye
      string options[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      if(digits==""){
          return ans;
      }

      combinations(stoi(digits),ans,output,options);
      return ans;   
    }
};