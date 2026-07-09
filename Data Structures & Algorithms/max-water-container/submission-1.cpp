class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max = 0;
        int i=0,j=n-1;
        while(i<j){
            if((min(height[i],height[j])*(j-i))>max) max = (min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return max;
    }
};
