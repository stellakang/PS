// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// O(logn)/O(1)

class Solution {
public:
    int firstBadVersion(int n) {
        long long int start=1,end=n;
        
        while(start<=end){
            long long int mid=(start+end)/2;
            if(!isBadVersion(mid))
                start=mid+1;
            else
                end=mid-1;
        }
        return end+1;
    }
};
