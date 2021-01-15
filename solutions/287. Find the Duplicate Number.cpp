class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) nums[nums[i]%n] += n;      //nums[i]%n just to get original array present before adding n to it
        for(int i=0;i<n;i++) if(nums[i]/n >1) return i;
            
 
        //O(n),O(n)
//         unordered_map<int,int> map;
//         int n = nums.size();
        
//         for(int i=0;i<n;i++) map[nums[i]]++;
//         for(auto i:map)
//         {
//             if(i.second >= 2){
//             return i.first;
//             }
//         }
       
        return 0;
    }
};
