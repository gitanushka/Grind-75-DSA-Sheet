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
    //head naam ka pointer banaya or dummy values key or value ke liye assign krdi
    node* head = new node(-1,-1);
    //same for tail pointer also
    node* tail = new node(-1,-1);
    //capacity store krne ke liye cap banaya
    int cap;
    //store krega key ko or us key ka jo address h hamara doubly linkedlist me use as  a value in map
    unordered_map<int,node*> mp;
    //new node add krenge   
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    // node ko delete krenge
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
        //agr hame hamari key miljaati h to
        if(mp.find(key)!=mp.end()){
            //ek node banayenge usme us key ka address dalenge jo map me h
            node* resnode = mp[key];
            //us address ke corresponding dll me jo value h use res me dal denge
            int res = resnode->val;
            //map se erase kr denge hamari key ko kyunki hamne use recently use kiya
            mp.erase(key);
            //ham list me se bhi us node ko delete kr denge for the same rsn
            deletenode(resnode);
            //firse ham node ko add kr denge list me head ke baad kyunki vo recently use hui hai
            addnode(resnode);
            //map me bhi add kr denge us key ko uske naye address ke saath
            mp[key] = head->next;
            //return kr denge ham amaar res ko jisne vo val hogi
            return res;
        }
        //in case hame ke nhi milti h to ham -1 return kr denge
          return -1;
    }
    
    void put(int key, int value) {
        //agr hame pehle hi map vo key mil jaat h to
        if(mp.find(key)!=mp.end()){
            //node banayenge jisme ham us map se key ka address le lenge
            node* existingnode = mp[key];
            //map se us key ko remove kr denge
            mp.erase(key);
            //ll se bhi us node ko erase kr denge
            deletenode(existingnode);
        }
        //agr hamari cache ki capacity full h toh
        if(mp.size()==cap){
           //ham recently used node ko joki tail ke prev wali hi hogi ko ham recently jo se krte jaare h use delete or add krke head ke baad lgate jaare h isiliye least recently used tail ke pehle wali hogi use remove kr denge map se
           mp.erase(tail->prev->key);
           //ll se bhi us node ko del kr denge
           deletenode(tail->prev);
        }
        //nayi key value ko ll me add kr denge
        addnode(new node(key,value));
        //map me us key ko store krenge or us key ke corresponding jo ll me address h use dal denge
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */