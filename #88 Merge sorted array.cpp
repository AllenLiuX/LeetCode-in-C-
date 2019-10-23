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