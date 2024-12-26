// https://leetcode.com/problems/merge-intervals

class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;

        std::stack<vector<int>> st;

        std::sort(intervals.begin(),
                  intervals.end(),
                  [](const vector<int> &x, const vector<int> &y) {
                      return x[0] < y[0];
                  });

        st.push(intervals[0]);

        for (std::size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > st.top()[1]) {
                st.push(intervals[i]);
                continue;
            }

            if (intervals[i][1] < st.top()[1])
                continue;
            else
                st.top()[1] = intervals[i][1];
        }

        vector<vector<int>> out;

        while (!st.empty()) {
            out.push_back(st.top());
            st.pop();
        }

        return out;
    }
};