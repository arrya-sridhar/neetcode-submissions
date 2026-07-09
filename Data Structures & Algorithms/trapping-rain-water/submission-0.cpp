class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), lmax = 0, rmax = 0, total = 0;
        vector<int> left(n,0), right(n,0);
        for(int i=0;i<n;i++){
            if(height[i]>lmax) lmax = height[i];
            if(lmax>height[i]) left[i] = lmax;
        }
        for(int i=n-1;i>=0;i--){
            if(height[i]>rmax) rmax = height[i];
            if(rmax>height[i]) right[i] = rmax;
        }
        for(int i=0;i<n;i++) if(min(left[i],right[i])>height[i]) total += min(left[i],right[i]) - height[i];
        return total;
    }
};
