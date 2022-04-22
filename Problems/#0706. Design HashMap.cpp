// #0706. Design HashMap
// https://leetcode.com/problems/design-hashmap/

#include<bits/stdc++.h>
using namespace std;

// Max space
class MyHashMap {
    vector<int> hashMap;
public:
    MyHashMap() {
        hashMap.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */