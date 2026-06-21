class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> width(n,1);
        for(int i=0;i<n;i++){
            if(i==0) for(int j=1;j<n;j++){
                if(heights[i]<=heights[j]) width[i]++;
                else break;
            }
            else if(i==n-1) for(int j=n-2;j>=0;j--){
                if(heights[i]<=heights[j]) width[i]++;
                else break;
            }    
            else{
                for(int j=i+1;j<n;j++){
                    if(heights[i]<=heights[j]) width[i]++;
                    else break;
                }    
                for(int j=i-1;j>=0;j--){
                    if(heights[i]<=heights[j]) width[i]++;
                    else break;
                }    
            }
        }
        int max=0;
        for(int i=0;i<n;i++){
            if(heights[i]*width[i]>max) max = heights[i]*width[i];
        }
        return max;
    }
};
