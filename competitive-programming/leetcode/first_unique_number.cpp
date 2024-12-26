// https://leetcode.com/problems/first-unique-number

class Node
{
  public:
    int key;
    bool unique;
    Node *prev, *next;

    Node(int k, bool u)
      : key(k)
      , unique(u)
      , prev(NULL)
      , next(NULL)
    {}
    Node()
    {}
    ~Node()
    {}
};

class FirstUnique
{

  public:
    Node *head, *tail;
    unordered_map<int, Node *> k2n;

    FirstUnique(vector<int> &nums)
    {
        this->head = new Node(-1, /*unique=*/true);
        this->tail = new Node(-1, /*unique=*/true);
        this->head->next = this->tail;
        this->tail->prev = this->head;

        for (int n : nums)
            this->add(n);
    }

    int showFirstUnique()
    {
        return this->head->next->key;
    }

    void add(int n)
    {
        auto it = this->k2n.find(n);

        if (it != this->k2n.end()) {
            // this value already exists (i.e. was unique until this point)
            // => remove from list
            if (it->second->unique) {
                remove_node(&(it->second));
                it->second->unique = false;
            }

            return;
        }

        Node *node = new Node(n, /*unique=*/true);
        this->k2n[n] = node;
        add_node_to_tail(&node);
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
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */