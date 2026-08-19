class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0), right(n,0);
        stack<int> ls,rs;
        for(int i=0;i<n;i++) right[i] = n-1-i;
        for(int i=0;i<n;i++) left[i] = i;
        for(int i=0;i<n;i++){
            while(rs.size()>0 && heights[i]<heights[rs.top()]){
                right[rs.top()] = i - rs.top() - 1;
                rs.pop();
            }
            rs.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(ls.size()>0 && heights[i]<heights[ls.top()]){
                left[ls.top()] = ls.top() - i - 1;
                ls.pop();
            }
            ls.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++) if(heights[i]*(1+left[i]+right[i])>ans) ans = heights[i]*(1+left[i]+right[i]);
        return ans;
    }
};
