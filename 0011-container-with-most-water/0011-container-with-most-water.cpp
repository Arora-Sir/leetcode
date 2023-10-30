class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxAre =0;
        // while(i!=height.size()-1){
            // j=height.size()-1;
            while(i<j){
                int min = height[i]<height[j]?height[i]:height[j];
                // maxAre = ((min*(j-1))>maxAre)?(min*(j-1)):maxAre;
                maxAre = max(maxAre, (j - i) * min);
                while (height[i] <= min && i < j) i++;
                while (height[j] <= min && i < j) j--;
            }
        // }
        return maxAre;
    }
};