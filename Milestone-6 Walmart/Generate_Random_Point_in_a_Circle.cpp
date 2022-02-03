class Solution {
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double ang = (double)rand() / RAND_MAX * 2 * M_PI,
               hyp = sqrt((double)rand() / RAND_MAX) * r,
               adj = cos(ang) * hyp,
               opp = sin(ang) * hyp;
        return {x + adj, y + opp};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
