class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(), k = groupSize;
        sort(hand.begin(),hand.end());
        if(n%k!=0) return false;
        unordered_map<int,int> count;
        for(int card : hand) count[card]++;
        for(int card : hand){
            if(count[card]==0) continue;
            for(int i=0;i<k;i++){
                if(count[card+i]==0) return false;
                else count[card+i]--;
            }
        }
        return true;
    }
};
