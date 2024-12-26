// https://leetcode.com/problems/last-stone-weight

class Solution
{
  public:
    bool step(vector<int> &v)
    {
        int s1, s2;

        s1 = v.front();
        pop_heap(v.begin(), v.end());
        v.pop_back();

        s2 = v.front();
        pop_heap(v.begin(), v.end());
        v.pop_back();

        if (s1 > s2) {
            v.push_back(s1 - s2);
            push_heap(v.begin(), v.end());
        }

        return v.size() > 1;
    }

    int lastStoneWeight(vector<int> &v)
    {
        if (v.size() == 1)
            return v[0];

        make_heap(v.begin(), v.end());

        while (step(v))
            ;

        return (v.size() == 1) ? v[0] : 0;
    }
};