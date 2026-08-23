class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int m = nums1.size(), n = nums2.size(), l=0, r=m;
        while(l<=r){
            int p1 = (l+r)/2, p2 = (m+n+1)/2 - p1, lmax1, lmax2, rmin1, rmin2;

            if(p1==0) lmax1 = INT_MIN;
            else lmax1 = nums1[p1-1];

            if(p1==m) rmin1 = INT_MAX;
            else rmin1 = nums1[p1];

            if(p2==0) lmax2 = INT_MIN;
            else lmax2 = nums2[p2-1];

            if(p2==n) rmin2 = INT_MAX;
            else rmin2 = nums2[p2];

            if(lmax1<=rmin2 && lmax2<=rmin1){
                if((m+n)%2!=0) return max(lmax1,lmax2);
                else return (double)(max(lmax1,lmax2)+min(rmin1,rmin2))/2;
            }
            else if(lmax1>rmin2) r = p1-1;
            else l = p1+1;
        }
        return 0.0;
    }
};
