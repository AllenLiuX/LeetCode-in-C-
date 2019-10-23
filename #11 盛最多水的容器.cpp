class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        for(int i=0; i<height.size(); i++){
            for(int j=i+1; j<height.size(); j++){
                int h = height[i]>height[j] ? height[j] : height[i];
                int area = h*(j-i);
                if(area>max)
                    max=area;
            }
        }
        return max;
    }
};