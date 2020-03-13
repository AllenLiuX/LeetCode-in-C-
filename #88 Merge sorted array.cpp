Tags: array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-- + n-- -1;
        while(m>=0 && n>=0){    //不会有nums1重复的情况，因为每一个被用完后指针m都会向前移
            if(nums2[n]>nums1[m]){
                nums1[p--] = nums2[n--];
            }
            else
                nums1[p--] = nums1[m--];
        }
        while(n>=0) //处理剩下的nums2
            nums1[p--] = nums2[n--];
    }
};