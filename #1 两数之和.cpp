class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> temp;
        for (int i=0; i< size-1; i++){
            for (int j=i+1; j < size; j++){
                if((nums[i]+nums[j]) == target){
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }
        }
        return temp;
    }
};