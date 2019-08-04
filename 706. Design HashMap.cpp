class HashEntry{
    public:
        int key;
        int value;
};

class MyHashMap {
    HashEntry** ht;
    int size = 1000000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        ht = new HashEntry * [size];
        for(int i=0; i<size; i++){
            ht[i] = NULL;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key%size;
        while(ht[idx] != NULL && ht[idx]->key != key){
            idx = (idx+1)%size;
        }
        ht[idx] = new HashEntry;
        ht[idx]->key = key;
        ht[idx]->value = value;        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx=key%size;
        while(ht[idx] != NULL){
            if(ht[idx]->key == key){
                return ht[idx]->value;
            }
            idx = (idx+1)%size;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx=key%size;
        while(ht[idx] != NULL ){
            if(ht[idx]->key == key)
                break;
            idx = (idx+1)%size;
        }
        ht[idx] = NULL;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
