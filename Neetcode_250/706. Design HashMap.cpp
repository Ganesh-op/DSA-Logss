class MyHashMap {
public:
    vector<int> table;
    MyHashMap() {
        table.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        table[key] = value;
    }
    
    int get(int key) {
        return table[key];
    }
    
    void remove(int key) {
        table[key] = -1;
    }
};