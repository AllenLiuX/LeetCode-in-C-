class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0 && nums[i-1]>=nums[i])
            i--;
        if(i==0){
            reverse(nums, 0);
                return;
        }
        int j = nums.size()-1;
        while(j>=i-1 && nums[j]<=nums[i-1])
            j--;
        swap(nums, i-1, j);
        reverse(nums, i);
    }
    
    void reverse(vector<int>& nums, int m){
        int n = nums.size()-1;
        while(m<n){
            swap(nums, m, n);
            m++;
            n--;
        }
    }
    
    void swap(vector<int>& nums, int m, int n){
        int temp = nums[m];
        nums[m] = nums[n];
        nums[n] = temp;
    }
};