/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int total_cnt=0;
        while(true){
            char tmp[4];
            int cnt=read4(tmp);
            for(int i=0;i<cnt;i++){
                if(total_cnt<n)
                    buf[total_cnt++]=tmp[i];
                else
                    break;
            }
            if(total_cnt>=n || cnt<4)break;
        }
        return total_cnt;
    }
};
