class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int point=m+n-1;
        int nums1Indx=m-1;
        int nums2Indx=n-1;
        
        while(nums1Indx>=0 && nums2Indx>=0){
            if(nums1[nums1Indx]>nums2[nums2Indx])
                nums1[point--]=nums1[nums1Indx--];
            else
                nums1[point--]=nums2[nums2Indx--];
        }
        while(nums2Indx>=0)
            nums1[point--]=nums2[nums2Indx--];
    }
};
