Tags: array
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0)
        return 0;
        //加入计数器，计算表中互不相同的元素个数
        int k=1;
        int p=nums[0];
        bool rep = false;
        //nums[i]为当前元素的结点
        for (int i=1;i<nums.size();i++){
            if (nums[i]!=p){
                nums[k]=nums[i];
                p=nums[i];
                k++;
                rep = false;    //注意这一步的位置，只有遇到新的才！rep
            }
            else if(!rep){
                nums[k] = nums[i];
                p=nums[i];
                k++;
                rep = true;
            }
        }
        return k;   //返回表长
    }
};