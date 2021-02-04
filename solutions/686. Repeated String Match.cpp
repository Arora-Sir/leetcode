class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string storeA = A;
        int count =(B.length()/A.length());
        for(int i=1;i<=count+2;i++){
            if(A.find(B) != -1 ) return i;  // -1 -> "string::npos" can also be written
            A += storeA;                  //It is defined like :  static const size_t npos = -1;
        }
        return -1;
    }
};
