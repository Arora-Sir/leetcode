class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        // Step 1: total area + y-range
        for (auto& sq : squares) {
            double y = sq[1];
            double side = sq[2];
            totalArea += side * side;
            low = min(low, y);
            high = max(high, y + side);
        }

        double target = totalArea / 2.0;

        // Step 2: binary search on y
        for (int iter = 0; iter < 60; iter++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto& sq : squares) {
                double bottom = sq[1];
                double top = sq[1] + sq[2];
                double side = sq[2];

                if (mid <= bottom) {
                    // contributes nothing
                } else if (mid >= top) {
                    areaBelow += side * side;
                } else {
                    areaBelow += side * (mid - bottom);
                }
            }

            if (areaBelow < target) {
                low = mid; // need more area below
            } else {
                high = mid; // too much area below
            }
        }

        return low;
    }
};