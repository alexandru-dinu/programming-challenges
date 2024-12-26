class Node
{
  public:
    int key, val;
    Node *prev, *next;

    Node(int k, int v)
      : key(k)
      , val(v)
      , prev(NULL)
      , next(NULL)
    {}
    Node()
    {}
    ~Node()
    {}
};

class LRUCache
{
  public:
    int capacity;

    // H -->more recent--> T
    Node *head, *tail;

    // key --> node(key, val)
    unordered_map<int, Node *> key2node;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    int get(int key)
    {
        auto it = this->key2node.find(key);

        if (it == this->key2node.end())
            return -1;

        // get + refresh
        Node *node = it->second;
        refresh(&node);

        return node->val;
    }

    void put(int key, int value)
    {
        auto it = this->key2node.find(key);

        // already exists -> remove node in order to refresh
        if (it != this->key2node.end())
            remove_node(&it->second);

        Node *node = new Node(key, value);
        add_node_to_tail(&node);
        this->key2node[key] = node;

        // evict oldest
        if (this->key2node.size() > this->capacity)
            evict_oldest();
    }

    void refresh(Node **node)
    {
        remove_node(node);
        add_node_to_tail(node);
    }

    void evict_oldest()
    {
        Node *oldest = this->head->next;
        this->key2node.erase(this->key2node.find(oldest->key));
        remove_node(&oldest);
    }

    void add_node_to_tail(Node **node)
    {
        Node *tail_prev = this->tail->prev;
        tail_prev->next = *node;
        this->tail->prev = *node;
        (*node)->prev = tail_prev;
        (*node)->next = this->tail;
    }

    void remove_node(Node **node)
    {
        if (!node)
            return;

        Node *prev = (*node)->prev;
        Node *next = (*node)->next;

        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
