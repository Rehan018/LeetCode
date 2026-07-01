class LRUCache {
    int cap;

    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        auto it = mp.find(key);

        if (it == mp.end())
            return -1;

        dll.splice(dll.begin(), dll, it->second);

        return it->second->second;
    }

    void put(int key, int value) {

        auto it = mp.find(key);

        if (it != mp.end()) {

            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }

        if (dll.size() == cap) {

            auto node = dll.back();
            mp.erase(node.first);
            dll.pop_back();
        }

        dll.emplace_front(key, value);
        mp[key] = dll.begin();
    }
};