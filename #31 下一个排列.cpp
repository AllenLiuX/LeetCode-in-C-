实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

---

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