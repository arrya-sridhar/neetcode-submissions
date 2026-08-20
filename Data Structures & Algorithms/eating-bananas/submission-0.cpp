class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), maxh=0;
        for(int i=0;i<n;i++) if(piles[i]>maxh) maxh = piles[i];
        int l=1, r=maxh, mid;
        while(l<=r){
            mid = (l+r)/2;
            int count = 0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid==0) count += piles[i]/mid;
                else count += piles[i]/mid + 1;
            }
            if(count<=h) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
