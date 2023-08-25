class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;

        int i = 0;
        //if any leading white spaces increase the i
        while(i<s.size() && s[i]==' '){
            i++;
        }
        //update s string with string from where there is no leading white space
        s = s.substr(i);

        int sign = 1;
        long ans = 0;

        if(s[0]=='-') sign = -1;
        int MAX = INT_MAX , MIN = INT_MIN;
         //if there is a sign in starting index then set i to next index nhi to aise hi rehne do
        i = (s[0]=='-' || s[0]=='+') ? 1 : 0;

        //traversing the string
        while(i<s.length()){
            //if found space after any digit or any character or alphabet then return onlt the digit traversed till it
            if(s[0]==' ' || !isdigit(s[i])) break;

            ans = ans * 10 + (s[i] - '0');
            if(sign== -1 && -1*ans < MIN) return MIN;
            if(sign==1 && ans > MAX ) return MAX;
            i++;
        }
        
        return (int)(sign*ans);

    }
};