class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int n = store[key].size(),l=0,r=n-1,m;
        if(n==0) return "";
        if(store[key][0].first > timestamp) return "";
        while(l<=r){
            m = (l+r)/2;
            if(store[key][m].first == timestamp) return store[key][m].second;
            else if(store[key][m].first>timestamp) r = m-1;
            else l = m+1;
        }
        return store[key][r].second;
    }
};
