class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size(),c0=0,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2]) continue;
            if(triplets[i][0]==target[0]) c0++;
            if(triplets[i][1]==target[1]) c1++;
            if(triplets[i][2]==target[2]) c2++;
        }
        if(c0>0 && c1>0 && c2>0) return true;
        else return false;
    }
};
