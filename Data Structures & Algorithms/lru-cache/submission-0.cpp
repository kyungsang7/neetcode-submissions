class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int cap;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> hash;
    
    int get(int key) {
        if(!hash.count(key)){
            return -1;
        }

        auto it = hash[key];
        cache.splice(cache.begin(), cache, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            auto it = hash[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
        }else{
            if(cache.size() >= cap){
                int oldkey = cache.back().first;
                hash.erase(oldkey);
                cache.pop_back();
            }

            cache.push_front({key, value});
            hash[key] = cache.begin();

        }
    }
};
