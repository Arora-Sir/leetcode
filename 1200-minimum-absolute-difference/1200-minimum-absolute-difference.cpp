class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        if(arr.size() <= 1) return ans;
        sort(arr.begin(),arr.end());
        int minDiff = INT_MAX;
        for(int i=1;i<arr.size();i++){
            minDiff = min(minDiff, arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            vector<int> subAns;
            if(arr[i]-arr[i-1] == minDiff){
                subAns.push_back(arr[i-1]);
                subAns.push_back(arr[i]);
                ans.push_back(subAns);
            }
        }
        return ans;
    }
};