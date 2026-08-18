class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(),count=1;
        if(n==0) return 0;
        vector<pair<int,double>> arr(n);
        for(int i=0;i<n;i++){
            arr[i].first = position[i];  
            arr[i].second = (float)(target - position[i])/speed[i];
        }    
        sort(arr.rbegin(),arr.rend());
        float time = arr[0].second;
        for(int i=0;i<n;i++){
            if(arr[i].second<=time) continue;
            else{
                count++;
                time = arr[i].second;
            }
        }
        return count;
    }
};
