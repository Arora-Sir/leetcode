class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int min = INT_MAX;
        char ans = letters[0];
        for(auto& letter : letters){
            if(letter - target < min && (letter-target>0)){
                min = letter - target;
                ans = letter;
            }
        }
        return ans;
    }
};