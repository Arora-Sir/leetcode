class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // as its already decreasing order, so no need to use min.
        // int min = INT_MAX;
        char ans = letters[0];
        for(auto& letter : letters){
            // if(letter - target < min && (letter-target>0)){
                // min = letter - target;
                if(letter > target){
                    return letter;
                }
            // }
        }
        return ans;
    }
};