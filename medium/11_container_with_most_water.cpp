class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int left=0,right=len-1;
        
        int maximum=0;
        while(left<right){
            int area=min(height[left],height[right])*(right-left);
            maximum=max(maximum,area);
            
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return maximum;
    }
};
