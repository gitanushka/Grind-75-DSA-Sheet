class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr(n,n);
        vector<int> nsl(n,-1);

        stack<int> st;
       //calculating nearest smaller to left
        for(int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nsl[i] = st.top();
            }
            st.push(i);
        } //empty stack
        while(!st.empty()) st.pop();
         //calculatng nearest smaller to right
       for(int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nsr[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){         //width for a particular bar
            ans = max(ans, heights[i]*(nsr[i]-nsl[i]-1));
        }
        return ans;        
    }
};