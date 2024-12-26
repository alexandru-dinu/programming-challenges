// https://leetcode.com/problems/min-stack

class MinStack
{

  private:
    list<int> xs; // values
    list<int> ms; // min values so far

  public:
    uint32_t size;

    MinStack()
    {
        xs = {};
        ms = { INT_MAX };
        size = 0;
    }

    void push(int x)
    {
        this->xs.push_back(x);
        this->ms.push_back(min(this->getMin(), x));
        this->size++;
    }

    void pop()
    {
        if (this->size == 0)
            return;

        this->xs.pop_back();
        this->ms.pop_back();
        this->size--;
    }

    int top()
    {
        if (this->size == 0)
            return INT_MIN; // err

        auto it = this->xs.end();
        return *(--it);
    }

    int getMin()
    {
        auto it = this->ms.end();
        return *(--it);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */