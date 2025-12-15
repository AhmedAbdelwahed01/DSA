struct Node {
    int key;
    int value;
    Node* left;
    Node* right;
    Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};
class LRUCache {
    Node* mru;
    Node* lru;
    int capacity;
    unordered_map<int, Node*> KeyToNode;
    void moveToEnd(Node* node) {
        Node* before = mru->right;

        node->right = before;
        node->left = mru;

        before->left = node;
        mru->right = node;
    }
    void removeNodeWiring(Node* node) {
        Node* right = node->right;
        Node* left = node->left;

        left->right = right;
        right->left = left;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {

        lru = new Node(1, 1);
        mru = new Node(1, 1);

        lru->left = mru;
        mru->right = lru;
    }

    int get(int key) {
        if (!KeyToNode.contains(key))
            return -1;
        auto node = KeyToNode[key];
        removeNodeWiring(node);
        moveToEnd(node);
        return node->value;
    }

    void put(int key, int value) {
        if (KeyToNode.contains(key)) {
            auto node = KeyToNode[key];
            removeNodeWiring(node);
            moveToEnd(node);
            node->value = value;
        } else {
            Node* node = new Node(key, value);
            moveToEnd(node);
            KeyToNode[key] = node;
            if (KeyToNode.size() > capacity) {
                auto node = lru->left;
                removeNodeWiring(node);
                KeyToNode.erase(node->key);
                delete node;
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