class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

   public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        if (cache.size() == capacity) {
            mp.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};