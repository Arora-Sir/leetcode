class Solution {
public:
    int maxConsecutiveGap(vector<int>& bars) {
        sort(bars.begin(), bars.end());

        int longest = 1;
        int curr = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
                longest = max(longest, curr);
            } else {
                curr = 1;
            }
        }

        // +1 because removing k consecutive bars creates gap of k+1
        return longest + 1;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {

        int maxHeight = maxConsecutiveGap(hBars);
        int maxWidth = maxConsecutiveGap(vBars);

        int side = min(maxHeight, maxWidth);
        return side * side;
    }
};