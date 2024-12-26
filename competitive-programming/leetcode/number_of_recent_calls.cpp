// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter
{
    queue<int> q;
    const int w = 3000;

  public:
    RecentCounter()
    {
        q = {};
    }

    int ping(int t)
    {
        if (q.empty()) {
            q.push(t);
        } else {
            // remove older timestamps
            while (q.size() > 0 && t - q.front() > w)
                q.pop();

            q.push(t);
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */