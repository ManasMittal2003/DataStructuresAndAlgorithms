class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxarea=INT_MIN;
        while(i<j){
            int area=min(height[i],height[j])*(j-i);
            maxarea=max(maxarea,area);
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxarea;
    }
};
