class MyHashMap {
private: 
    vector<vector<pair<int,int>>> mp;
    const int size = 10000;
public:
    MyHashMap() {
        mp.resize(size);
    }
    
    void put(int key, int value) {
        int idx = key%size;
        vector<pair<int,int>> &row = mp[idx];
        for(auto it = row.begin(); it!=row.end(); it++){
            if(it->first == key){
                it->second = value;
                return;
            }
        }
        row.push_back({key,value});
    }
    
    int get(int key) {
        int idx = key%size;
        vector<pair<int,int>> &row = mp[idx];
        for(auto it = row.begin(); it!=row.end(); it++){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = key%size;
        vector<pair<int,int>> &row = mp[idx];
        for(auto it = row.begin(); it!=row.end(); it++){
            if(it->first == key){
                row.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */