class LRUCache {
public:
    class node{
    public:    
       int key;
       int val;
       node* prev;
       node* next;
       node(int nkey, int nval){
           key = nkey;
           val = nval;
       }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    unordered_map<int,node*> mp;
      
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode){
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head->next;
            return res;
        }
          return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* existingnode = mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if(mp.size()==cap){
           mp.erase(tail->prev->key);
           deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */