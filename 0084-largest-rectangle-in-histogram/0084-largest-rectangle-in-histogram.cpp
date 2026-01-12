// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int maxArea = 0;
//         for (int i = 0; i < heights.size(); i++) {
//             int right = 0;
//             int left = 0;
//             int area = 0;
//             int current = heights[i];
//             for (int j = i - 1; j >= 0 && current <= heights[j]; j--) {
//                 left--;
//             }
//             for (int j = i + 1; j < heights.size() && current <= heights[j];
//                  j++) {
//                 right++;
//             }
//             area = (right - left + 1) * current;
//             maxArea = max(maxArea, area);
//         }
//         return maxArea;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st; // stores indices of bars
        int maxArea = 0;
        int n = heights.size();

        // Loop goes till n to force processing of all bars
        for (int i = 0; i <= n; i++) {

            // If i == n, pretend current bar height is 0
            int currHeight = (i == n ? 0 : heights[i]);

            // If current bar is smaller, rectangles must end
            while (!st.empty() && currHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    // No smaller bar on the left
                    // Rectangle spans from index 0 to i-1
                    width = i;
                } else {
                    // Left boundary = st.top()
                    // Right boundary = i - 1
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, height * width);
            }

            // Push current bar index
            st.push(i);
        }

        return maxArea;
    }
};