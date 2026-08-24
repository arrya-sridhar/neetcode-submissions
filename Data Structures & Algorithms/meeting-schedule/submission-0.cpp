/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        unordered_map<int,int> hash;
        for(Interval ins : intervals){
            hash[ins.start]++;
            hash[ins.end]++;
            for(int i=ins.start+1;i<ins.end;i++) hash[i] += 2;
        }
        for(auto& pair : hash) if(pair.second>2) return false;
        return true;
    }
};
