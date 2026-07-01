class LFUCache {
    struct Node {
        int key;
        int val;
        int freq;
    };

    int cap;
    int minFreq;

    unordered_map<int, list<Node>> freqList;
    unordered_map<int, list<Node>::iterator> keyNode;

    void update(list<Node>::iterator it) {

        Node node = *it;
        int f = node.freq;

        freqList[f].erase(it);

        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f)
                ++minFreq;
        }

        ++node.freq;

        freqList[node.freq].push_front(node);
        keyNode[node.key] = freqList[node.freq].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {

        auto it = keyNode.find(key);

        if (it == keyNode.end())
            return -1;

        int value = it->second->val;

        update(it->second);

        return value;
    }

    void put(int key, int value) {

        if (cap == 0)
            return;

        auto it = keyNode.find(key);

        if (it != keyNode.end()) {

            it->second->val = value;
            update(it->second);
            return;
        }

        if (keyNode.size() == cap) {

            auto &lst = freqList[minFreq];

            auto node = lst.back();

            keyNode.erase(node.key);

            lst.pop_back();

            if (lst.empty())
                freqList.erase(minFreq);
        }

        minFreq = 1;

        freqList[1].push_front({key, value, 1});
        keyNode[key] = freqList[1].begin();
    }
};