// https://leetcode.com/problems/generate-random-point-in-a-circle

#include <random>

class Solution
{
  private:
    uniform_real_distribution<double> unif{ 0, 1 };
    random_device rd;
    const double PI = acos(-1);

  public:
    double r, cx, cy;
    Solution(double radius, double x_center, double y_center)
      : r(radius)
      , cx(x_center)
      , cy(y_center)
    {}

    vector<double> rs()
    {
        double x = (cx - r) + unif(rd) * 2 * r;
        double y = (cy - r) + unif(rd) * 2 * r;

        double dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);

        if (dist <= r * r)
            return { x, y };
        else
            return rs();
    }

    vector<double> pc()
    {
        // see
        // https://stackoverflow.com/questions/5837572/generate-a-random-point-within-a-circle-uniformly
        double l = sqrt(unif(rd)) * r;
        double a = unif(rd) * 2 * PI;

        return { cx + l * cos(a), cy + l * sin(a) };
    }

    vector<double> randPoint()
    {
        return rs();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */