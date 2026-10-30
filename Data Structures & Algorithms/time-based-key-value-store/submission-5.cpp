class TimeMap {
public:
    TimeMap() {
        
    }
    
    map<string, vector<pair<int,string>>> st;

    void set(string key, string value, int timestamp) {
        st[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int n = st[key].size();
        int left = 0, right = n-1;

        while(left <= right){
            int mid = (left + right) / 2;
            if (st[key][mid].first <= timestamp){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if (right < 0){
            return "";
        }
        return st[key][right].second;
    }
};
