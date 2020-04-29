class MapSum {

private:
    bool isEnd = false;
    MapSum * next[26];
    int value;

    void dfs(MapSum * root, int &sumResult) {
        if (root->isEnd) sumResult += root->value;
        for (auto pn: root->next){
            if (pn != nullptr) 
                dfs(pn, sumResult);
        }
    }

public:
    /** Initialize your data structure here. */
    MapSum() {
        isEnd = false;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
    
    void insert(string key, int val) {
        MapSum *node = this;
        for (char c: key) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new MapSum();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
        node->value = val;
    }
    
    int sum(string prefix) {
        MapSum * node = this;
        for (char c: prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr) return 0;
        }
        int sumResult = 0;
        dfs(node, sumResult);
        return sumResult;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */