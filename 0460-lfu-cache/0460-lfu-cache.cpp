class LFUCache {
public:
    int size;
    int n;

    map<int, list<vector<int>>> freq;  // freq -> list of {key, value, freq}
    unordered_map<int, list<vector<int>>::iterator> mp; // key -> iterator to its position in list

    LFUCache(int capacity) {
        n = capacity;
        size = 0;
    }

    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]);
        int value = vec[1];
        int counter = vec[2];

        freq[counter].erase(mp[key]);
        if(freq[counter].empty()) freq.erase(counter);

        counter++;
        freq[counter].push_front({key, value, counter});
        mp[key] = freq[counter].begin();
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        int value = (*(mp[key]))[1];
        makeMostFrequentlyUsed(key);

        return value;
    }

    void put(int key, int value) {
        if(n == 0) return;

        if(mp.find(key) != mp.end()) {
            auto &vec = *(mp[key]);
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else {
            if(size == n) {
                auto &del = freq.begin()->second;
                int keyDel = del.back()[0];
                del.pop_back();

                if(del.empty()) freq.erase(freq.begin()->first);
                mp.erase(keyDel);
            } else {
                size++;
            }

            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();
        }
    }
};
