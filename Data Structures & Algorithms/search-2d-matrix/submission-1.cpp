class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), l=0, r=m-1, mid;
        while(l<=r){
            mid = (l+r)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n-1]) break;
            else if(target>=matrix[mid][0]) l = mid + 1;
            else r = mid - 1;
        }
        l = 0;
        r = n-1;
        while(l<=r){
            int nmid = (l+r)/2;
            if(matrix[mid][nmid]==target) return true;
            else if(matrix[mid][nmid]>target) r = nmid - 1;
            else l = nmid + 1;
        }
        return false;
    }
};
