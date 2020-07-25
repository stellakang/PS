// time complexity: O(1)
// space complexity: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            uint32_t b=n&1;
            if(b==1)cnt++;
            n=n>>1;
        }
        return cnt;
    }
};


