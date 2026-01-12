class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // heights[j] = height of histogram at column j
        vector<int> heights(cols, 0);

        int maxArea = 0;

        // Process row by row
        for (int i = 0; i < rows; i++) {

            // Build histogram heights
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1; // increase height
                else
                    heights[j] = 0; // reset height
            }

            // Calculate largest rectangle in histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    // Standard Largest Rectangle in Histogram
    // Monotonic increasing stack
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; //stack holds indices, so height increases as we go up the stack
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            // If we are at real bars -> use their height
            // If we are at imaginary last bar -> height = 0
            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};