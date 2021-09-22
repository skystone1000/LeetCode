// Company Amazon
// 01 #0146 LRU Cache
// https://leetcode.com/problems/lru-cache/


class LRUCache {
    list <pair <int,int> > cache;
    unordered_map<int, list<pair<int,int>>::iterator> mymap;
    int capacity;
    
    void refreshPosition(int key, int value){
        cache.erase(mymap[key]);
        cache.push_front({key,value});
        mymap[key] = cache.begin();
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mymap.find(key) != mymap.end()){
            refreshPosition(key, (*mymap[key]).second);
            return (*mymap[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mymap.find(key) != mymap.end())
            refreshPosition(key,value);
        else{
            cache.push_front({key,value});
            mymap[key] = cache.begin();
            if(mymap.size() > capacity){
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */