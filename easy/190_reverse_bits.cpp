class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed=0;
        int steps=32;
        while(steps--){
            uint32_t b= n & 1;
            reversed = reversed<<1;
            reversed |= b;
            n = n>>1;
        }
        return reversed;
    }
};
