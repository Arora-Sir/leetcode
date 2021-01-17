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
