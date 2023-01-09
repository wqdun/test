#include <iostream>
#include <unordered_map>
#include <list>

class LRU_fail {
public:
    LRU_fail() {};
    ~LRU_fail() {};

    bool full() {
        return (data.size() >= max_size);
    }

    int get(int k) {
        if (data.find(k) == data.end()) {
            return -1;
        }

        int val = data[k];
        active(k, val);

        return val;
    }

    void put(int k, int val) {
        if (!full()) {
            data.insert(data.begin(), std::make_pair(k, val));
        }
        else {
            pop_front();
            data.insert(data.begin(), std::make_pair(k, val));
        }

        return;
    }

    void pop_front() {
        const auto it = data.begin();
        std::cout << "Pop: " << it->first << ":" << it->second << "\n";
        data.erase(data.begin());
        return;
    }

    void active(int k, int val) {
        erase_by_key(k);
        data.insert(data.begin(), std::make_pair(k, val));
        return;
    }

    void erase_by_key(int k) {
        for (const auto it = data.begin(); it != data.end();) {
            if (it->first == k) {
                data.erase(it);
                return;
            }
        }

        return;
    }

    void print_data() {
        for (const auto &a: data) {
            std::cout << a.first << ":" << a.second << "    ";
        }
        std::cout << "\n";
        return;
    }

private:
    std::unordered_map<int, int> data {};
    size_t max_size = 10;
};

template <typename K, typename V>
class Entry {
public:
    explicit Entry() {};
    ~Entry() {};

    explicit Entry(K k, V v)
        : key(k)
        , value(v) {}

public:
    K key;
    V value;
};

template<typename T>
class LRU {
public:
    LRU() {};
    ~LRU() {};

    int get(int key) {
        // for (const Entry &e: data) {
        //     if (key == e.key) {
        //         return e.value;
        //     }
        // }
        T res;
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (key == it->key) {
                res = *it;
                data.erase(it);
                data.push_back(res);
                return res.value;
            }
        }

        std::cerr << "Failed to find: " << key << "\n";
        return -1;
    }

    void put(const T &e) {
        if (data.size() < max_size) {
            data.push_back(e);
        }
        else {
            data.pop_front();
            data.push_back(e);
        }

        return;
    }

    void print_data() {
        for (const T &e: data) {
            std::cout << "k: " << e.key << "; v: " << e.value << "\t";
        }
        std::cout << "\n";
    }

private:
    std::list<T> data {};
    size_t max_size = 10;
};

int main(int argc, char const *argv[]) {
    LRU<Entry<int, int>> cache;
    for (size_t i = 0; i < 16; ++i) {
        cache.put(Entry<int, int>(i, i));
        cache.print_data();
    }

    std::cout << cache.get(8) << "\n";
    cache.print_data();
    return 0;
}
