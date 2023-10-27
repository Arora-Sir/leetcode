class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        int i = 0;

        while (i < size) {
            // Check if the current plot and its adjacent plots are all empty
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;  // Plant a flower in the current plot
                count++;  // Increase the count of planted flowers
            }
            i++;
        }

        return count >= n;  // Return true if enough flowers have been planted
    }
};