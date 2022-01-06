class Solution {
public:
    double findMedianSortedArrays(vector<int>& vec1, vector<int>& vec2) {
        int m = vec1.size();
        int n = vec2.size();
        vector<double> v;
        
        for(int i=0;i<m;i++){
            v.push_back(vec1[i]);
        }
        for(int i=0;i<n;i++){
            v.push_back(vec2[i]);
        }
        sort(v.begin(),v.end());
        
        if ((m+n) % 2 == 0)
            return (v[((m+n) / 2) - 1] + v[(m+n) / 2]) / 2;
        else
            return v[(m+n) / 2];
    }
};
​
//done in O((m+n)log(m+n))
​
//if we compare one one element by taking i & j
//then complexity can ve reduced to O(m+n), as sort fnction not needed
​
// but it can be optimized to O(log(m+n))
// Calculate the median of both the arrays and discard one half of each array. 
