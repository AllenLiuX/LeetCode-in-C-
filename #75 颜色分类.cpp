class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size()-1;
        int cur = 0;
        while(cur<=p2){ //等于很重要！交换后最后一个也需要考虑！比如201->102,此时cur和p2都等于1.
            if(nums[cur]==0){
                swap(nums[p0++], nums[cur++]);
            }
            else if(nums[cur]==2){
                swap(nums[p2--], nums[cur]);
            }
            else{
                cur++;
            }
        }
    }
};