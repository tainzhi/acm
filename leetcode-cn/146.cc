/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct Node
{
    int key, value;
    struct Node *pre, *next;
    Node(): key(0), value(0), pre(nullptr), next(nullptr){}
    Node(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr){}
};
class LRUCache {
private:
    int size = 0;
    int capacity = 0;
    unordered_map<int, Node*> buck;
    Node * hair = new Node(), *tail = new Node();
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        buck = unordered_map<int, Node*>();
        hair->next = tail;
        tail->pre = hair;
    }
    
    int get(int key) {
        if (buck.count(key) != 0) {
            Node *t = buck[key];
            t->pre->next = t->next;
            t->next->pre = t->pre;
            hair->next->pre = t;
            t->next = hair->next;
            hair->next = t;
            t->pre = hair;
            return hair->next->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (buck.count(key)) {
            buck[key]->value = value;
            get(key);
        } else {
            if (size == capacity) {
                removeTail();
            }
            addHead(key, value);
        }
    }

    void removeTail() {
        size--;
        Node * t = tail;
        buck.erase(tail->pre->key);
        tail->pre->next = tail->next;
        tail = tail->pre;
        delete  t;
    }

    void addHead(int key, int value) {
        // 添加到头部
        size++;
        Node * t = new Node(key, value);
        buck[key] = t;
        hair->next->pre = t;
        t->next = hair->next;
        t->pre = hair;
        hair->next = t;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

